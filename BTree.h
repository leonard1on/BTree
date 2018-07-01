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
  void sort(BTreeNode*);
  void insert(Key*);
  void split(BTreeNode*);
  BTreeNode* getLeaf(BTreeNode*, string);
  void printPrevious(BTreeNode*);
  int findIndex(BTreeNode*, string);
};
#endif
