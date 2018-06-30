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

void BTree::insert(Key* key){
  BTreeNode* temp = new BTreeNode(T);
  temp = root;
  /*while (!temp->isLeaf()) {

    for (int i = 1; i <= temp->getKeys()->size; i++) {
      if (key<temp->getKeysAt(i)) {
        temp = temp->getChildrenAt(i);
      } else if (key>temp->getKeysAt(i)) {
        cout<<"si";
        temp = temp->getChildrenAt(i+1);
      }
    }
    //temp = temp->getChildrenAt(2);
  }*/
  temp = getLeaf(temp, key->getKey());

  temp->getKeys()->insert(key);
  temp->getKeys()->sort();

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
    top->addChild(left);
    top->addChild(right);
    root = top;
  }else{
    top->getKeys()->insert(node->getKeysAt(half));
    left->setParent(top);
    top->getChildren()->replace(top->getChildren()->size, left);

    top->addChild(right);
  }

  if (top->getKeys()->size > T-1) {
    split(top);
  }

}

BTreeNode* BTree::getLeaf(BTreeNode* node, int key){
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
