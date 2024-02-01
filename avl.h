#ifndef AVL_H
#define AVL_H

#include <stdbool.h>

struct AvlNode {
  long key;
  struct AvlNode *left, *right;
  int height;
};

#define  ANODE  struct AvlNode
#define pANODE  struct AvlNode*

// Inserts a new node into the AVL
pANODE avlInsert(long key, pANODE node);

// Removes a node from the AVL
pANODE avlRemove(long key, pANODE root);

// Searches for a node in the AVL
pANODE avlSearch(long key, pANODE root);

#endif