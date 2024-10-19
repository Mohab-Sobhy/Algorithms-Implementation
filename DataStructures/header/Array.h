//
// Created by mohab on 10/14/24.
//

#ifndef ARRAY_H
#define ARRAY_H

template<class Value>
struct Array
{
private:
	int  n, sz;//n -> size of array | sz -> number of elemnts that alrady exist in array
	Value* arr;

public:
	void Initialize();
	void Initialize(int _n);
	void Destroy();
	void AddLast(Value v);
	void RemoveLast();
	Value& operator[](int i);
	void print();
	int getNumOfElements();
	//Array();
};
#include "../src/Array.tpp"

#endif //ARRAY_H
