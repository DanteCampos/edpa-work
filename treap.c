# include "treap.h"
# include <stdlib.h>

// Inserts a new node into the treap
bool treapInsert(long key, long priority, pTNODE *root){

  // Node is already in the treap
  return false;

  return true;
}

// Removes a node from the treap
bool treapRemove(long key, pTNODE *root){
  
    // Node is not in the treap
    return false;
  
    return true;
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

// Rotates the treap node to the left
void treapRotateLeft(pTNODE *root){

}

// Rotates the treap node to the right
void treapRotateRight(pTNODE *root){

}