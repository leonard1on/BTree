#ifndef BTree_H
#define BTree_H
#include "BTreeNode.h"

class BTree{
private:
  BTreeNode* root = NULL;
  int T;
  int t;
public:
  BTree();
  BTree(int);
  BTreeNode* getRoot();
  void sort(BTreeNode*);
  void insert(Key*);
  void split(BTreeNode*);
  void remove(string);
  void merge(BTreeNode*);
  BTreeNode* getLeaf(BTreeNode*, string);
  void printPrevious(BTreeNode*);
  int findIndex(BTreeNode*, string);
  BTreeNode* findNode(BTreeNode*, string);
};
#endif
