#include "BTree.h"
#include "BTreeNode.h"
#include "List.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  BTree* tree = new BTree(3);
  tree->insert(1);
  tree->insert(2);
  tree->insert(3);
  tree->insert(4);
  tree->insert(5);
  tree->insert(6);
  tree->insert(7);

  for (int i = 1; i <= tree->getRoot()->getKeys()->size; i++) {
    cout<<'['+ to_string(tree->getRoot()->getKeysAt(i))+']';
  }
  cout<<endl;

  for (int i = 1; i <= tree->getRoot()->getChildren()->size; i++) {
    for(int j=1; j <= tree->getRoot()->getChildrenAt(i)->getKeys()->size; j++){
      cout<<'['+to_string(tree->getRoot()->getChildrenAt(i)->getKeysAt(j))+']';
    }
    cout<<endl;
  }


  return 0;
}
