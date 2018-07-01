/*Double-link List*/

#ifndef LIST_H
#define LIST_H

//#include <QDebug>

template <class T>
class ListNode{
protected:
  T data;
  ListNode<T>* previous;
  ListNode<T>* next;

public:
  ListNode<T>(T nData){
    data = nData;
    previous = 0;
    next = 0;
  }

  T getData(){
    return data;
  }

  T* getDataPointer(){
      return &data;
  }

  ListNode<T>* getPrevious(){
    return previous;
  }

  ListNode<T>* getNext(){
    return next;
  }

  void setData(T nData){
    data = nData;
  }

  void setPrevious(ListNode<T>* nPrevious){
    previous = nPrevious;
  }

  void setNext(ListNode<T>* nNext){
    next = nNext;
  }

  ~ListNode(){
    if (next != 0) {
      delete next;
    }

    previous = 0;
  }
};

template <class T>
class List{
protected:
  ListNode<T>* head;
  ListNode<T>* tail;

public:
  int size;
  int capacity;

  List<T>(){
    head = 0;
    tail = 0;
    size = 0;
    capacity = -1;
  }

  List<T>(int nCap){
    head = 0;
    tail = 0;
    size = 0;
    capacity = nCap;
  }

  void setCapacity(int nCapacity){
    capacity = nCapacity;
  }

  bool insert(T data){
    if (size >= capacity && capacity != -1) {
      return false;
    }else{
      ListNode<T>* temp = new ListNode<T>(data);

      if (head == 0) {
        head = temp;
        tail = temp;
      }else{
        temp->setPrevious(tail);
        tail->setNext(temp);
        tail = temp;
      }

      size ++;
      return true;
    }
  }

  T get(int index){
      ListNode<T>* currentListNode = head;

      for (int i = 2; i <= index; i++) {
        if (currentListNode != 0) {
          currentListNode = currentListNode->getNext();
        }
      }

      return currentListNode->getData();
  }

  T* getPointer(int index){
      ListNode<T>* currentListNode = head;

      for (int i = 2; i <= index; i++) {
        if (currentListNode != 0) {
          currentListNode = currentListNode->getNext();
        }
      }

      return currentListNode->getDataPointer();
  }

  bool replace(int index, T nData){
      ListNode<T>* currentListNode = head;

      for (int i = 2; i <= index; i++) {
        if (currentListNode != 0) {
          currentListNode = currentListNode->getNext();
        }
      }

      if (currentListNode != 0){
        currentListNode->setData(nData);
        return true;
      }

      return false;
  }


  bool remove(int index){
    if (index > size) {
      return false;
    }else{
      ListNode<T>* currentListNode = head;

      for (int i = 2; i <= index; i++) {
        currentListNode = currentListNode->getNext();
      }

      ListNode<T>* prev = currentListNode->getPrevious();
      ListNode<T>* next = currentListNode->getNext();

      if (prev != 0) {
        prev->setNext(next);
      }

      if (next != 0) {
        next->setPrevious(prev);

        if (prev == 0) {
          head = next;
        }
      }else{
        if (size == 2) {
          tail = head;
        }
      }

      currentListNode->setPrevious(0);
      currentListNode->setNext(0);

      size --;

      if (size == 2) {
        head->setNext(tail);
        tail->setPrevious(head);
      }

      return true;
    }
  }

  void clear(){
    if (head != 0) {
      delete head;
    }

    head = 0;
    tail = 0;
    size = 0;
  }

  bool isEmpty(){
    if (size == 0) {
      return true;
    }

    return false;
  }

  bool isFull(){
    if (size >= capacity && capacity != -1) {
      return true;
    }

    return false;
  }

  bool contains(T target){
    for (int i = 1; i <= size; i++) {
      if (target == get(i)) {
        return true;
      }
    }

    return false;
  }

  bool contains(T target, T exclude){
    for (int i = 1; i <= size; i++) {
      if (target == get(i)) {
        if (exclude == get(i)) {
          return false;
        }
        return true;
      }
    }

    return false;
  }

  int indexOf(T dat){
    ListNode<T>* currentListNode = head;
    int count = 0;

    while (currentListNode != 0) {
      count ++;

      if (currentListNode->getData() == dat) {
        return count;
      }else{
        currentListNode = currentListNode->getNext();
      }
    }

    return 0;
  }

  ListNode<T>* getListNode(int index){
    if (index <= 1) {
      return head;
    }else{
      ListNode<T>* currentListNode = head;

      for (int i = 2; i <= index; i++) {
        currentListNode = currentListNode->getNext();
      }

      return currentListNode;
    }
  }

  ListNode<T>* findListNode(T dat){
    ListNode<T>* currentListNode = head;

    while (currentListNode != 0) {
      if (currentListNode->getData() == dat) {
        return currentListNode;
      }else{
        currentListNode = currentListNode->getNext();
      }
    }

    return 0;
  }


  void swap(int i1, int i2){
    if (i1 <= size && i2 <= size && i1 > 0 && i2 > 0) {
      ListNode<T>* n1 = getListNode(i1);
      ListNode<T>* n2 = getListNode(i2);

      T tmp = n1->getData();
      n1->setData(n2->getData());
      n2->setData(tmp);
    }
  }

  void sort(){
    if (size < 2) {
      return;
    }

    for (int i = 1; i <= size; i++) {
      for (int j = 1; j < size; j++) {
        if (get(j) > get(j + 1)) {
          swap(j, j + 1);
        }
      }
    }
  }

  List<T> clone(){
    List<T> nList;

    for (int i = 1; i <= size; i++) {
      nList.insert(get(i));
    }

    return nList;
  }

  T operator[](int index){
      return get(index);
  }

  T dequeue(){
    T temp = head.getData();
    remove(1);
    return temp;
  }

  ~List<T>(){
    /*if (head != 0) {
      delete head;
    }*/
  }
};

#endif /* end of include guard: LIST_H */
