
#include "DataStructures/header/DisjointSets.h"
#include "Problems/Problems.h"
#include <iostream>
using namespace std;

int main() {

    DisjointSets ds;
    ds.Initialize(8);
    ds.Union(2,3);
    ds.Union(4,3);
    ds.Union(7,3);
    ds.Print();

    return 0;
}