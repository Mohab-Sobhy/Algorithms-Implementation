//
// Created by mohab on 10/19/24.
//

#ifndef QUEUE_H
#define QUEUE_H

template <class Type>
struct Queue
{
    int f, n;
    int capacity;
    Type* elems;

    void Initialize(int size);
    void Destroy();
    void Add(Type t);
    Type Pop();
    Type Peek();
    int Num();
};
#include "../src/Queue.tpp"

#endif //QUEUE_H
