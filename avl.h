#ifndef AVL_H
#define AVL_H

#include <stdbool.h>

#define  ANODE  struct AvlNode
#define pANODE  struct AvlNode*

struct AvlNode {
  long key;
  ANODE *left, *right;
};

// Inserts a new node into the AVL
bool avlInsert(long key, pANODE *root);

// Removes a node from the AVL
bool avlRemove(long key, pANODE *root);

// Searches for a node in the AVL
pANODE avlSearch(long key, pANODE root);

// Rotates the AVL node to the left
void avlRotateLeft(pANODE *root);

// Rotates the AVL node to the right
void avlRotateRight(pANODE *root);

#endif