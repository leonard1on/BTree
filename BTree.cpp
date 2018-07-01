#include "BTree.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

BTree::BTree() {
}

BTree::BTree(int pT) {
  root = new BTreeNode(pT);
  T=pT;
}

BTreeNode* BTree::getRoot(){
  return root;
}

void BTree::sort(BTreeNode* node){
  List<Key> temp;
  for (int i = 1; i <= node->getKeys()->size; i++) {
    temp.insert(*node->getKeysAt(i));
  }
  temp.sort();
  node->getKeys()->clear();

  for (int i = 1; i <= temp.size; i++) {
    node->getKeys()->insert(temp.getPointer(i));
  }
}

void BTree::insert(Key* key){
  BTreeNode* temp = new BTreeNode(T);
  temp = root;
  temp = getLeaf(temp, key->getKey());
  temp->getKeys()->insert(key);
  sort(temp);
  if (temp->getKeys()->size > temp->getT()-1) {
    split(temp);
  }

}

void BTree::split(BTreeNode* node){
  BTreeNode* top = node->getParent();
  BTreeNode* left = new BTreeNode(T);
  BTreeNode* right = new BTreeNode(T);
  int half = 1 + ((node->getKeys()->size-1) / 2);
  //int key = node->getKeysAt(node->getKeys()->size);

  for (int i = 1; i <= node->getKeys()->size; i++) {
    if (i<half) {
      left->getKeys()->insert(node->getKeysAt(i));
    }else if (i>half) {
      right->getKeys()->insert(node->getKeysAt(i));
    }
  }

  for (int i = 1; i <= node->getChildren()->size; i++) {
    if (i<=half) {
      left->addChild(node->getChildrenAt(i));
    }else {
      right->addChild(node->getChildrenAt(i));
    }
  }

  if (top == NULL) {
    top = new BTreeNode(T);
    top->getKeys()->insert(node->getKeysAt(half));
    sort(top);
    top->addChild(left);
    top->addChild(right);
    root = top;
  }else{
    int index = top->getChildren()->indexOf(node);
    top->getKeys()->insert(node->getKeysAt(half));
    sort(top);
    left->setParent(top);
    top->getChildren()->replace(index, left);
    top->addChild(right);
    for (int i = top->getChildren()->size; i > index+1; i--) {
      top->getChildren()->swap(i, i-1);
    }
  }

  if (top->getKeys()->size > T-1) {
    split(top);
  }

}

BTreeNode* BTree::getLeaf(BTreeNode* node, string key){
  bool bandera = false;
  if (!node->isLeaf()) {

    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key < node->getKeysAt(i)->getKey() && !bandera) {
        node = node->getChildrenAt(i);
        bandera = true;
      }
    }

    if (!bandera) {
      node = node->getChildrenAt(node->getChildren()->size);
    }

    node = getLeaf(node, key);
  }
  return node;
}

int BTree::findIndex(BTreeNode* node, string key){
  bool bandera = false;
  if (!node->isLeaf()) {

    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key == node->getKeysAt(i)->getKey()) {
        return node->getKeysAt(i)->getIndex();
      } else if (key < node->getKeysAt(i)->getKey() && !bandera) {
        node = node->getChildrenAt(i);
        bandera = true;
      }
    }

    if (!bandera) {
      node = node->getChildrenAt(node->getChildren()->size);
    }

    return findIndex(node, key);
  }else{
    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key == node->getKeysAt(i)->getKey()) {
        return node->getKeysAt(i)->getIndex();
      }
    }
  }
  return -1;
}
void BTree::printPrevious(BTreeNode* node){
//  cout<<"~~"+node->toString() <<endl;
  if (!node->isLeaf()) {
    printPrevious(node->getChildrenAt(1));
    cout<< node->toString()<<endl;
    for (int i = 2; i <= node->getChildren()->size; i++) {
      printPrevious(node->getChildrenAt(i));
    }
  }else{
    cout<<node->toString()<<endl;
  }
}






////////////////////////////////////////////////////////////////////////////
