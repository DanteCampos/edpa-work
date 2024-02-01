# include "treap.h"
# include <stdlib.h>

pTNODE newTNODE(long key, long priority){
  pTNODE newNode = (pTNODE)malloc(sizeof(TNODE));
  newNode->key = key;
  newNode->priority = priority;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Rotates the treap node to the left
void treapRotateLeft(pTNODE *root){
  pTNODE temp = (*root)->right;
  (*root)->right = temp->left;
  temp->left = *root;
  *root = temp;
}

// Rotates the treap node to the right
void treapRotateRight(pTNODE *root){
  pTNODE temp = (*root)->left;
  (*root)->left = temp->right;
  temp->right = *root;
  *root = temp;
}

// Inserts a new node into the treap
bool treapInsert(long key, long priority, pTNODE *root){
  // If the treap is empty, create a new node
  if (*root == NULL) {
    *root = newTNODE(key, priority);
    return true;
  }

  // If the key is already in the treap, return false
  if (key == (*root)->key) {
    return false;
  }

  // If the key is less than the root's key, insert into the left subtree
  if (key < (*root)->key) {
    if (!treapInsert(key, priority, &(*root)->left)) {
      return false;
    }
    // If the left child's priority is greater than the root's priority, rotate right
    if ((*root)->left->priority > (*root)->priority) {
      treapRotateRight(root);
    }
  } else {
    // Otherwise, insert into the right subtree
    if (!treapInsert(key, priority, &(*root)->right)) {
      return false;
    }
    // If the right child's priority is greater than the root's priority, rotate left
    if ((*root)->right->priority > (*root)->priority) {
      treapRotateLeft(root);
    }
  }

  return true;
}

// Removes a node from the treap
bool treapRemove(long key, pTNODE *root){
  // If the treap is empty, return false
  if (*root == NULL) {
    return false;
  }

  // If the key is less than the root's key, remove from the left subtree
  if (key < (*root)->key) {
    return treapRemove(key, &(*root)->left);
  } else if (key > (*root)->key) {
    // If the key is greater than the root's key, remove from the right subtree
    return treapRemove(key, &(*root)->right);
  } else {
    // If the key is equal to the root's key, remove the root
    if ((*root)->left == NULL) {
      pTNODE temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
      pTNODE temp = *root;
      *root = (*root)->left;
      free(temp);
    } else {
      // If the root has two children, swap it with its predecessor or successor, then remove it
      if ((*root)->left->priority < (*root)->right->priority) {
        treapRotateLeft(root);
        treapRemove(key, root); // Continue "bubbling down" the node
      } else {
        treapRotateRight(root);
        treapRemove(key, root); // Continue "bubbling down" the node
      }
    }
    return true;
  }
}

// Searches for a node in the treap
pTNODE treapSearch(long key, pTNODE root){
  pTNODE target = root;

  // If the treap is empty, the node is not in the BST
  if (target == NULL)
    return NULL;

  // If the treap is not empty, search for the node recursively
  if (key < target->key)
    return treapSearch(key, target->left);
  if (key > target->key)
    return treapSearch(key, target->right);

  // Found the node
  return target;
}