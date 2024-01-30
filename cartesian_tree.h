/*cartesian_tree.h*/

#include <time.h>
#include <stdlib.h>
#include <limits.h>


#ifndef _CARTESIAN_TREE_H_
#define _CARTESIAN_TREE_H_

#define  NODE  struct Node
#define pNODE  struct Node*
#define ppNODE struct Node**

/* Each node of the tree has the following structure: */
struct Node {
  long key, priority;   /* priority is a kind of `technical' information */
  char* assoc;          /* pointer to a user's data (imagine MAP) */
  NODE *left, *right;   /* links to the left and right child */
};

/* Returns a pointer to the tree consisting only from the root */
pNODE construct_tree(void);

/* Inserts new element to the tree.
   Returns 0 if there was no such element in tree and -1 otherwise
   (in such case, nothing is inserted) */
char insert(pNODE, long, char*);

/* Erases a node with a particular key.
   returns 0 if an element with key `key' was deleted
   and -1 otherwise. */
char erase(pNODE, long);

/* Returns a pointer to node with the particular key
   or NULL if there is no such node. */
pNODE find(pNODE, long);

/* Clean up. One should call this function every time
   when the tree isn't needed no more. */
void destruct_tree(pNODE);


#endif

/*cartesian_tree.h*/




