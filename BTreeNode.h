#ifndef BTreeNode_h
#define BTreeNode_h
#include "List.h"
#include <vector>
#include <string>

using namespace std;

class BTreeNode{
  private:
    List<int>* keys;
    List<BTreeNode*>* children;
    BTreeNode* parent = NULL;
    int T;
  public:
    //Constructor
    BTreeNode();
    BTreeNode(int);

    //Gets
    List<int>* getKeys();
    int getKeysAt(int);
    int getT();
    BTreeNode* getParent();

    bool isLeaf();
    List<BTreeNode*>* getChildren();
    BTreeNode* getChildrenAt(int);
    void addChild(BTreeNode*);
    void removeLastChild();
};
#endif
