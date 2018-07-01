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
     tree->insert(new Key(to_string(i),i+1));
   }
  // tree->insert(new Key(40,0));
  // tree->insert(new Key(39,0));
  // tree->insert(new Key(28,0));
  // tree->insert(new Key(27,0));
  // tree->insert(new Key(26,0));
  // tree->insert(new Key(29,0));
  // tree->insert(new Key(30,0));
  cout<<to_string(tree->findIndex(tree->getRoot(), "41"));
  //tree->printPrevious(tree->getRoot());
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
