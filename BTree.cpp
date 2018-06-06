#include "BTree.h"
#include <string>
#include <vector>

using namespace std;

BTree::BTree() {
}

BTree::BTree(int pT) {
  root = new BTreeNode(pT);
  T=pT;
}

void BTree::insert(int data){
  BTreeNode* temp = new BTreeNode(T);
  temp = root;
  while (!temp->isLeaf()) {

    for (int i = 0; i < T; i++) {
      if (i==T-1) {
        temp = temp->getChildrenAt(i);
      } else if (data<temp->getDataAt(i)) {
        temp = temp->getChildrenAt(i);
      }
    }

  }
  temp->getData().push_back(data);
  if (temp->getData().size() >= temp->getT()-1) {
    //split
  }

}
