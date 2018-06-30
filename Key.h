#ifndef KEY_H
#define KEY_H
class Key {
private:
  int key;
  int index;

public:
  Key();
  Key (int, int);

  //Gets
  int getKey();
  int getIndex();

  bool operator>(Key* right);
  virtual ~Key ();
};
#endif
