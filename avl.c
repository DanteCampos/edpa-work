# include "avl.h"
# include <stdlib.h>

// Simple maximum function
int max(int a, int b) {
  return (a > b) ? a : b;
}

// Calculate height
int avlHeight(pANODE n) {
  if (n == NULL)
    return 0;
  return n->height;
}

// Create a node
pANODE newANODE(long key) {
  pANODE node = (pANODE) malloc(sizeof(ANODE));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

// Get the balance factor
int getAvlBalance(pANODE n) {
  if (n == NULL)
    return 0;
  return avlHeight(n->left) - avlHeight(n->right);
}

// Right rotate
pANODE avlRotateRight(pANODE y) {
  pANODE x = y->left;
  pANODE T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(avlHeight(y->left), avlHeight(y->right)) + 1;
  x->height = max(avlHeight(x->left), avlHeight(x->right)) + 1;

  return x;
}

// Left rotate
pANODE avlRotateLeft(pANODE x) {
  pANODE y = x->right;
  pANODE T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(avlHeight(x->left), avlHeight(x->right)) + 1;
  y->height = max(avlHeight(y->left), avlHeight(y->right)) + 1;

  return y;
}

pANODE minValueANODE(pANODE node) {
  while (node->left != NULL)
    node = node->left;
  return node;
}

// Insert node
pANODE avlInsert(long key, pANODE node) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newANODE(key));

  if (key < node->key)
    node->left = avlInsert(key, node->left);
  else if (key > node->key)
    node->right = avlInsert(key, node->right);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = max(avlHeight(node->left), avlHeight(node->right)) + 1;

  int balance = getAvlBalance(node);
  if (balance > 1 && key < node->left->key)
    return avlRotateRight(node);

  if (balance < -1 && key > node->right->key)
    return avlRotateLeft(node);

  if (balance > 1 && key > node->left->key) {
    node->left = avlRotateLeft(node->left);
    return avlRotateRight(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = avlRotateRight(node->right);
    return avlRotateLeft(node);
  }

  return node;
}


// Delete a nodes
pANODE avlRemove(long key, pANODE root) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = avlRemove(key, root->left);
  else if (key > root->key)
    root->right = avlRemove(key, root->right);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      pANODE temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      pANODE temp = minValueANODE(root->right);
      root->key = temp->key;
      root->right = avlRemove(temp->key, root->right);
    }
  }
  if (root == NULL)
    return root;

  // Update the balance factor of each node and balance the tree
  root->height = 1 + max(avlHeight(root->left), avlHeight(root->right));

  int balance = getAvlBalance(root);
  if (balance > 1 && getAvlBalance(root->left) >= 0)
    return avlRotateRight(root);
  if (balance > 1 && getAvlBalance(root->left) < 0) {
    root->left = avlRotateLeft(root->left);
    return avlRotateRight(root);
  }
  if (balance < -1 && getAvlBalance(root->right) <= 0)
    return avlRotateLeft(root);
  if (balance < -1 && getAvlBalance(root->right) > 0) {
    root->right = avlRotateRight(root->right);
    return avlRotateLeft(root);
  }
  return root;
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