#ifndef TREAP_H
#define TREAP_H

#include <stdbool.h>

#define  TNODE  struct TreapNode
#define pTNODE  struct TreapNode*

struct TreapNode {
  long key, priority;
  TNODE *left, *right;
};

// Inserts a new node into the treap
bool treapInsert(long key, long priority, pTNODE *root);

// Removes a node from the treap
bool treapRemove(long key, pTNODE *root);

// Searches for a node in the treap
pTNODE treapSearch(long key, pTNODE root);

// Rotates the treap node to the left
void treapRotateLeft(pTNODE *root);

// Rotates the treap node to the right
void treapRotateRight(pTNODE *root);

#endif