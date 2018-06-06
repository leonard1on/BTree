#include "BTreeNode.h"
BTreeNode::BTreeNode(){
}

BTreeNode::BTreeNode(int t){
  T=t;
}

vector<int> BTreeNode::getData(){
  return data;
}

int BTreeNode::getDataAt(int posicion){
  return data.at(posicion);
}

int BTreeNode::getT(){
  return T;
}

bool BTreeNode::isLeaf(){
  return children.size()==0;
}

vector<BTreeNode*> BTreeNode::getChildren(){
  return children;
}

BTreeNode* BTreeNode::getChildrenAt(int posicion){
  return children.at(posicion);
}
