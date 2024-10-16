#include <iostream>
#include "DataStructures/header/Array.h"
#include "DataStructures/header/Heap.h"
using namespace std;

int main()
{
    Heap<int> heap;
    heap.Initialize(IsBeforeInt);

    heap.Add(4);
    heap.Add(9);
    heap.Add(2);
    heap.Add(14);
    heap.Add(23);

    cout<<heap.GetFirst();




    return 0;
}
