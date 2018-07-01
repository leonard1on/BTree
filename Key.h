#ifndef KEY_H
#define KEY_H
#include <string>
#include <iostream>
using namespace std;
class Key {
private:
  string key;
  int index;

public:
  Key();
  Key (string, int);

  //Gets
  string getKey();
  int getIndex();

  void setKey(string);
  void setIndex(int);

  bool operator >(Key right);
  virtual ~Key ();
};
#endif
