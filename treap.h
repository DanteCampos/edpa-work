#ifndef TREAP_H
#define TREAP_H

#include <stdbool.h>

struct TreapNode {
  long key, priority;
  struct TreapNode *left, *right;
};

#define  TNODE  struct TreapNode
#define pTNODE  struct TreapNode*

// Inserts a new node into the treap
bool treapInsert(long key, long priority, pTNODE *root);

// Removes a node from the treap
bool treapRemove(long key, pTNODE *root);

// Searches for a node in the treap
pTNODE treapSearch(long key, pTNODE root);

#endif