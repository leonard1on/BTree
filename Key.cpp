#include "Key.h"

Key::Key(){
  key="";
  index=-1;
}

Key::Key(string pKey, int pIndex){
  key = pKey;
  index = pIndex;
}

string Key::getKey(){
  return key;
}

int Key::getIndex(){
  return index;
}

void Key::setKey(string pKey){
  key=pKey;
}

void Key::setIndex(int pIndex){
  index=pIndex;
}

bool Key::operator >(Key right){
//  cout<<to_string(key)+"~~"+to_string(right.getKey());
  if(key > right.getKey()){
    return true;
  }else{
    return false;
  }
}
Key::~Key(){}
