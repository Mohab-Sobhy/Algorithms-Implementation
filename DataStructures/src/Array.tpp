//
// Created by mohab on 10/14/24.
//
#pragma once

#include <iostream>
using namespace std;

template <typename Value>
void Array<Value>::Initialize() {
    n = 2;
    sz = 0;
    arr = new Value[n];
    cout<<"Array was successfully initialized!\n";
}

template <typename Value>
void Array<Value>::Initialize(int _n) {
    n = _n;
    sz = 0;
    arr = new Value[n];
    cout<<"Array was successfully initialized!\n";
}

template <typename Value>
void Array<Value>::Destroy() {
    delete [] arr;
    arr = nullptr;
    cout<<"Array was successfully destoroid!\n";
}

template <typename Value>
void Array<Value>::AddLast(Value v) {
    if(sz >= n) {
        n *= 2;
        Value* newArr = new Value[n];
        for(int i=0;i<sz;i++) {
            newArr[i]=arr[i];
        }
        delete [] arr;
        arr = newArr;
    }

    arr[sz] = v;
    sz++;
}

template<typename Value>
void Array<Value>::RemoveLast() {
    try {
        if(sz <= 0) {
            throw runtime_error("can't remove, the array is empty.");
        }
        if(sz < n/2) {
            n /= 2;
            Value* newArr = new Value[n];
            for(int i=0;i<sz-1;i++) {
                newArr[i]=arr[i];
            }
            delete [] arr;
            arr = newArr;
        }
        sz--;
    }
    catch (const exception& e) {
        cerr<<e.what();
    }
}

template <typename Value>
Value& Array<Value>::operator[](int i) {
    return arr[i];
}

template <typename Value>
void Array<Value>::print() {
    try {
        if(sz <= 0) {
            throw runtime_error("can't print, the array is empty");
        }
        for(int i=0;i<sz;i++) {
            cout<<arr[i]<<' ';
        }
        cout<<"\n";
    }
    catch (const runtime_error& e) {
        cerr<<e.what()<<endl;
    }
}

template<class Value>
int Array<Value>::getNumOfElements() {
    return sz;
}

/*
template<class Value>
Array<Value>::Array() {
    Initialize();
}
*/