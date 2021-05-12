// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
 private:
    T* array;
    int size;
    int begin,
        end;
    int counter;
 public:
TPQueue();
    ~TPQueue();
    void push(const T&);
    T pop();
    T get() const;
    bool isEmpty() const;
    bool isFull() const;
};
template<typename T>
TPQueue<T>::TPQueue() : size(100),
begin(0), end(0), counter(0) {
    array = new T[size + 1];
}
template<typename T>
TPQueue<T>::~TPQueue() {
  delete [] array;
}
template<typename T>
void TPQueue<T>::push(const T & item) {
  assert(counter < size);
  if (end != 0) {
      for (int i = end - 1; i > -1; --i) {
          if (array[i].prior >= item.prior) {
              array[i + 1] = item;
              continue;
          }

          if (array[i].prior < item.prior) {
              array[i + 1] = array[i];
              if (i == 0) {
                  array[i] = item;
              }
              continue;
          }
      }
  } else {
      array[begin] = item;
  }
  counter++;
  end++;
}
template<typename T>
T TPQueue<T>::pop() {
  assert(counter > 0);
  T item = array[begin++];
  counter--;

  if (begin > size) {
      begin -= size + 1;
  }
  
  return item;
}
template<typename T>
T TPQueue<T>::get() const {
  assert(counter > 0);
  return array[begin];
}
template<typename T>
bool TPQueue<T>::isEmpty() const {
  return counter == 0;
}
template<typename T>
bool TPQueue<T>::isFull() const {
  return counter == size;
}
struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
