# include "avl.h"
# include <stdlib.h>

// Inserts a new node into the AVL
bool avlInsert(long key, pANODE *root){

  // Node is already in the AVL
  return false;

  return true;
}

// Removes a node from the AVL
bool avlRemove(long key, pANODE *root){
  
    // Node is not in the AVL
    return false;
  
    return true;
}

// Searches for a node in the AVL
pANODE avlSearch(long key, pANODE root){
  pANODE target = root;

  // If the AVL is empty, the node is not in the BST
  if (target == NULL)
    return NULL;

  // If the AVL is not empty, search for the node recursively
  if (key < target->key)
    return avlSearch(key, target->left);
  if (key > target->key)
    return avlSearch(key, target->right);

  // Found the node
  return target;
}

// Rotates the AVL node to the left
void avlRotateLeft(pANODE *root){

}

// Rotates the AVL node to the right
void avlRotateRight(pANODE *root){

}