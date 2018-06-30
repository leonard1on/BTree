#ifndef BTree_H
#define BTree_H
#include "BTreeNode.h"

class BTree{
private:
  BTreeNode* root = NULL;
  int T;
public:
  BTree();
  BTree(int);
  BTreeNode* getRoot();
  void insert(int);
  void split(BTreeNode*);
  BTreeNode* getLeaf(BTreeNode*, int);
  void printPrevious(BTreeNode*);
};
#endif
