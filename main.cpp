#include "BTree.h"
#include "BTreeNode.h"
#include "List.h"
#include "Key.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  BTree* tree = new BTree(3);
  for (int i = 1; i <= 40; i++) {
    tree->insert(new Key(i,0));
  }

  tree->printPrevious(tree->getRoot());
  /*for (int i = 1; i <= tree->getRoot()->getKeys()->size; i++) {
    cout<<'['+ to_string(tree->getRoot()->getKeysAt(i))+']';
  }
  cout<<endl;

  for (int i = 1; i <= tree->getRoot()->getChildren()->size; i++) {
    for(int j=1; j <= tree->getRoot()->getChildrenAt(i)->getKeys()->size; j++){
      cout<<'['+to_string(tree->getRoot()->getChildrenAt(i)->getKeysAt(j))+']';
    }
    for (int k = 1; k <= tree->getRoot()->getChildrenAt(i)->getChildren()->size; k++) {
      for (int r = 1; r <=tree->getRoot()->getChildrenAt(i)->getChildrenAt(k)->getKeys()->size; r++){
        cout<<'{'+to_string(tree->getRoot()->getChildrenAt(i)->getChildrenAt(k)->getKeysAt(r))+'}';
      }
    }
    cout<<endl;
  }*/


  return 0;
}
