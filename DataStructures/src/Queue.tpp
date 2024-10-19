#include "../header/Array.h"

template<class Type>
void Queue<Type>::Initialize(int size) {
    f = n = 0;
    capacity = size;
    elems = new Type[size];
}

template<class Type>
void Queue<Type>::Destroy() {
    delete [] elems;
}

template<class Type>
void Queue<Type>::Add(Type t) {
    if (n == capacity) {
        throw std::overflow_error("Queue is full");
    }
    elems[n] = t;
    n++;
}

template<class Type>
Type Queue<Type>::Pop() {
    if (n == 0) {
        throw std::underflow_error("Queue is empty");
    }
    Type temp = elems[f];
    for (int i = 0; i < n - 1; i++) {
        elems[i] = elems[i + 1];
    }
    n--;
    return temp;
}

template<class Type>
Type Queue<Type>::Peek() {
    if (n == 0) {
        throw std::underflow_error("Queue is empty");
    }
    return elems[f];
}

template<class Type>
int Queue<Type>::Num() {
    return n;
}
