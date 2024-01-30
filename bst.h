#ifndef BST_H
#define BST_H

#include <stdbool.h>

#define  BNODE  struct BstNode
#define pBNODE  struct BstNode*

struct BstNode {
  long key;
  BNODE *left, *right;
};

// Inserts a new node into the BST
bool bstInsert(long key, pBNODE *root);

// Removes a node from the BST
bool bstRemove(long key, pBNODE *root);

// Searches for a node in the BST
pBNODE bstSearch(long key, pBNODE root);

#endif