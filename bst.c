# include "bst.h"
# include <stdlib.h>

// Inserts a new node into the BST
bool bstInsert(long key, pBNODE *root){
  // If the BST is empty, create a new node
  if (*root == NULL) {
    *root = (pBNODE) malloc(sizeof(BNODE));
    (*root)->key = key;
    (*root)->left = NULL;
    (*root)->right = NULL;
    return true;
  }

  // If the BST is not empty, insert the node recursively
  if (key < (*root)->key)
    return bstInsert(key, &(*root)->left);
  if (key > (*root)->key)
    return bstInsert(key, &(*root)->right);
    
  // Node is already in the BST
  return false;
}

// Removes a node from the BST
bool bstRemove(long key, pBNODE *root){
  // If the BST is empty, the node is not in the BST
  if (*root == NULL)
    return false;
  
  // If the BST is not empty, remove the node recursively
  if (key < (*root)->key)
    return bstRemove(key, &(*root)->left);
  if (key > (*root)->key)
    return bstRemove(key, &(*root)->right);
  
  // Found the node to be removed
  // If the node has no children, remove it
  if ((*root)->left == NULL && (*root)->right == NULL) {
    free(*root);
    *root = NULL;
    return true;
  }

  // If the node has one child, replace it with its child
  if ((*root)->left == NULL) { // Case node has only right child
    pBNODE child = *root;
    *root = (*root)->right;
    free(child);
    return true;
  }
  if ((*root)->right == NULL) { // Case node has only left child
    pBNODE child = *root;
    *root = (*root)->left;
    free(child);
    return true;
  }

  // If the node has two children, replace it with its successor
  pBNODE succ = (*root)->right;
  while (succ->left != NULL)
    succ = succ->left;
  (*root)->key = succ->key; // Replacing the node
  return bstRemove(succ->key, &(*root)->right); // Removing the successor from the original position

}

// Searches for a node in the BST
pBNODE bstSearch(long key, pBNODE root){
  pBNODE target = root;

  // If the BST is empty, the node is not in the BST
  if (target == NULL)
    return NULL;

  // If the BST is not empty, search for the node recursively
  if (key < target->key)
    return bstSearch(key, target->left);
  if (key > target->key)
    return bstSearch(key, target->right);
  
  // Found the node
  return target;
}