#ifndef BTreeNode_h
#define BTreeNode_h
#include "List.h"
#include "Key.h"
#include <vector>
#include <string>

using namespace std;

class BTreeNode{
  private:
    List<Key*>* keys;
    List<BTreeNode*>* children;
    BTreeNode* parent = NULL;
    int T;
    int t;
  public:
    //Constructor
    BTreeNode();
    BTreeNode(int);

    //Gets
    List<Key*>* getKeys();
    Key* getKeysAt(int);
    int getT();
    int getMin();
    BTreeNode* getParent();
    void setParent(BTreeNode*);

    bool isLeaf();
    List<BTreeNode*>* getChildren();
    BTreeNode* getChildrenAt(int);
    void addChild(BTreeNode*);
    void removeLastChild();
    string toString();

    ~BTreeNode();
};
#endif
