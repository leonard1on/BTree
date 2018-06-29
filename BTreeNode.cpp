#include "BTreeNode.h"
BTreeNode::BTreeNode(){
}

BTreeNode::BTreeNode(int t){
  T=t;
  keys = new List<int>;
  children = new List<BTreeNode*>;
}

//Gets
List<int>* BTreeNode::getKeys(){
  return keys;
}

int BTreeNode::getKeysAt(int posicion){
  return keys->get(posicion);
}

int BTreeNode::getT(){
  return T;
}

BTreeNode* BTreeNode::getParent(){
  return parent;
}


bool BTreeNode::isLeaf(){
  return children->size==0;
}

List<BTreeNode*>* BTreeNode::getChildren(){
  return children;
}

BTreeNode* BTreeNode::getChildrenAt(int posicion){
  return children->get(posicion);
}

void BTreeNode::addChild(BTreeNode* child){
  child->parent = this;
  children->insert(child);
}

void BTreeNode::removeLastChild(){
  children->remove(children->size);
}
