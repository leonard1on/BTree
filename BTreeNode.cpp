#include "BTreeNode.h"
BTreeNode::BTreeNode(){
}

BTreeNode::BTreeNode(int pT){
  T=pT;
  t=(pT-1)/2;
  keys = new List<Key*>;
  children = new List<BTreeNode*>;
}

//Gets
List<Key*>* BTreeNode::getKeys(){
  return keys;
}

Key* BTreeNode::getKeysAt(int posicion){
  return keys->get(posicion);
}

int BTreeNode::getT(){
  return T;
}

int BTreeNode::getMin(){
  return t;
}

BTreeNode* BTreeNode::getParent(){
  return parent;
}

void BTreeNode::setParent(BTreeNode* node){
    parent=node;
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

string BTreeNode::toString(){
  string temp ="";
  for (int i = 1; i <= keys->size; i++) {
    temp+="["+ (keys->get(i)->getKey()) + '/' +to_string(keys->get(i)->getIndex());
  }
  temp+="]";
  return temp;
}

BTreeNode::~BTreeNode(){

}
