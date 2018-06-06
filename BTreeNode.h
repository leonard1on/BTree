#ifndef BTreeNode_h
#define BTreeNode_h
#include <vector>
#include <string>

using namespace std;

class BTreeNode{
  private:
    vector<int> data;
    vector<BTreeNode*> children;
    BTreeNode* parent = NULL;
    int T;
  public:
    BTreeNode();
    BTreeNode(int);
    vector<int> getData();
    int getDataAt(int);
    int getT();
    bool isLeaf();
    vector<BTreeNode*> getChildren();
    BTreeNode* getChildrenAt(int);

};
#endif
