//
// Created by mohab on 10/16/24.
//

#ifndef HEAP_H
#define HEAP_H
#include "Array.h"

template<typename Elem>
struct Heap {
private:
    Array<Elem> a;
    bool (*IsBefore)(Elem&, Elem&);//   pointer for IsBeforeInt function

public:
    void Initialize(bool (*_IsBefore)(Elem&, Elem&));
    void Destroy();
    int Child(int i);
    int Parent(int i);
    void MoveUp(int ind);
    void MoveDown(int ind);
    void Add(Elem e);
    Elem GetFirst();
    Elem RetrieveFirst();
    void Print();//     from me
};
#include "../src/Heap.tpp"

#endif //HEAP_H
