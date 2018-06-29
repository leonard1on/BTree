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
void BTree::insert(int key){
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
  temp = getLeaf(temp, key);

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

  for (int i = 1; i <= node->getKeys()->size; i++) {
    if (i<half) {
      left->getKeys()->insert(node->getKeysAt(i));
    }else if (i>half) {
      right->getKeys()->insert(node->getKeysAt(i));
    }
  }

  for (int i = 1; i <= node->getChildren()->size; i++) {
    if (i<half) {
      left->getChildren()->insert(node->getChildrenAt(i));
    }else {
      right->getChildren()->insert(node->getChildrenAt(i));
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
    top->getChildren()->replace(top->getChildren()->size, left);
    top->addChild(right);
  }

  if (top->getKeys()->size > T-1) {
    split(top);
  }

}

BTreeNode* BTree::getLeaf(BTreeNode* root, int key){
  bool bandera = false;
  if (!root->isLeaf()) {

    for (int i = 1; i <= root->getKeys()->size; i++) {
      if (key < root->getKeysAt(i) && !bandera) {
        root = root->getChildrenAt(i);
        bandera = true;
      }
    }

    if (!bandera) {
      root = root->getChildrenAt(root->getChildren()->size);
    }

    getLeaf(root, key);
  }
  return root;
}






////////////////////////////////////////////////////////////////////////////
