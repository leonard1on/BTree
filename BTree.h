#ifndef BTree_H
#define BTree_H
#include "BTreeNode.h"

class BTree{
public:
  BTreeNode* root = NULL;
  int T;
private:
  BTree();
  BTree(int);
  void insert(int);
};
#endif
