#include "Key.h"

Key::Key(){
  key=0;
  index=-1;
}

Key::Key(int pKey, int pIndex){
  key = pKey;
  index = pIndex;
}

int Key::getKey(){
  return key;
}

int Key::getIndex(){
  return index;
}


bool Key::operator>(Key* right){
  if(key > right->getKey()){
    return true;
  }else{
    return false;
  }
}
Key::~Key(){}
