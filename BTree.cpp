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
  t=(pT-1)/2;
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

void BTree::remove(string key){
  BTreeNode* temp = new BTreeNode(T);
  temp = root;
  temp = findNode(temp, key);
  for (int i = 1; i <= temp->getKeys()->size; i++) {
    if (key==temp->getKeysAt(i)->getKey()) {
      temp->getKeys()->remove(i);
    }
  }
  if (temp->getKeys()->size < t) {
    merge(temp);
  }
}

void BTree::merge(BTreeNode* node){
  BTreeNode* top = node->getParent();
  BTreeNode* left = new BTreeNode(T);
  BTreeNode* right = new BTreeNode(T);
  if (top==NULL) {

  }else{
    int index = top->getChildren()->indexOf(node);
    if (index == 1) {
      right = top->getChildrenAt(index+1);
      node->getKeys()->insert(top->getKeysAt(index));
      top->getKeys()->remove(index);

      for (int i = 1; i <= right->getKeys()->size  ; i++) {
        node->getKeys()->insert(right->getKeysAt(i));
      }
      for (int i = 1; i <= right->getChildren()->size  ; i++) {
        node->getChildren()->insert(right->getChildrenAt(i));
      }

      top->getChildren()->remove(index+1);
      if (node->getKeys()->size > T) {
        split(node);
      }
      if (top->getKeys()->size < t) {
        merge(top);
      }

    } else if(index = top->getChildren()->size){
      left = top->getChildrenAt(index-1);
      left->getKeys()->insert(top->getKeysAt(index));
      top->getKeys()->remove(index);

      for (int i = 1; i <= right->getKeys()->size  ; i++) {
        left->getKeys()->insert(node->getKeysAt(i));
      }
      for (int i = 1; i <= right->getChildren()->size  ; i++) {
        left->getChildren()->insert(node->getChildrenAt(i));
      }
      top->getChildren()->remove(index);

      if (left->getKeys()->size > T) {
        split(node);
      }
      if (top->getKeys()->size < t) {
        merge(top);
      }
    }else{
      left = top->getChildrenAt(index-1);
      right = top->getChildrenAt(index+1);
      if (left->getKeys()->size > right->getKeys()->size) {
        left->getKeys()->insert(top->getKeysAt(index));
        top->getKeys()->remove(index);
        for (int i = 1; i <= right->getKeys()->size  ; i++) {
          left->getKeys()->insert(node->getKeysAt(i));
        }
        for (int i = 1; i <= right->getChildren()->size  ; i++) {
          left->getChildren()->insert(node->getChildrenAt(i));
        }
        top->getChildren()->remove(index);

        if (left->getKeys()->size > T) {
          split(node);
        }
        if (top->getKeys()->size < t) {
          merge(top);
        }
      }else{
        node->getKeys()->insert(top->getKeysAt(index));
        top->getKeys()->remove(index);

        for (int i = 1; i <= right->getKeys()->size  ; i++) {
          node->getKeys()->insert(right->getKeysAt(i));
        }
        for (int i = 1; i <= right->getChildren()->size  ; i++) {
          node->getChildren()->insert(right->getChildrenAt(i));
        }

        top->getChildren()->remove(index+1);
        if (node->getKeys()->size > T) {
          split(node);
        }
        if (top->getKeys()->size < t) {
          merge(top);
        }
      }
    }
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

BTreeNode* BTree::findNode(BTreeNode* node, string key){
  bool bandera = false;
  if (!node->isLeaf()) {

    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key == node->getKeysAt(i)->getKey()) {
        return node;
      } else if (key < node->getKeysAt(i)->getKey() && !bandera) {
        node = node->getChildrenAt(i);
        bandera = true;
      }
    }

    if (!bandera) {
      node = node->getChildrenAt(node->getChildren()->size);
    }

    return findNode(node, key);
  }else{
    for (int i = 1; i <= node->getKeys()->size; i++) {
      if (key == node->getKeysAt(i)->getKey()) {
        return node;
      }
    }
  }
  return NULL;
}

void BTree::printPrevious(BTreeNode* node){
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
