//
// Created by mohab on 10/16/24.
//
#include <iostream>
#include "../DataStructures/header/Heap.h"
using namespace std;

int Add_All() {
    Heap <int> heap;
    heap.Initialize(IsBeforeInt);
    int numOfIntegers = 0;
    int lastCost = 0;
    int totalCost = 0;
    while(1){
        cin >> numOfIntegers;
        if(numOfIntegers == 0) {
            break;
        }

        lastCost = 0;
        totalCost = 0;

        for(int i=0 ; i<numOfIntegers ; i++) {
            int num;
            cin >> num;
            heap.Add(num);
        }
        lastCost = heap.RetrieveFirst() + heap.RetrieveFirst();
        totalCost = lastCost;
        for(int i=2 ; i<numOfIntegers ; i++) {
            lastCost += heap.RetrieveFirst();
            totalCost += lastCost;
        }

        cout << totalCost <<'\n';
    }

    return 0;
}