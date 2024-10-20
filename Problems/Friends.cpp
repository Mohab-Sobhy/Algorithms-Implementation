//
// Created by mohab on 10/20/24.
//

#include "../DataStructures/header/DisjointSets.h"
#include <iostream>
using namespace std;

int Friends() {

    DisjointSets ds;
    //
    int numOfTestCases;
    cin >> numOfTestCases;

    while(numOfTestCases--) {
        int numOfCitizen;
        int numOfRelations;
        cin >> numOfCitizen;
        cin >> numOfRelations;
        ds.Initialize(numOfCitizen);
        while(numOfRelations--) {
            int friendOneIndex;
            int friendTwoIndex;
            cin >> friendOneIndex >> friendTwoIndex;
            ds.Union(friendOneIndex-1 , friendTwoIndex-1);
        }

        cout<< ds.FindLargestSetNodes() << endl;
    }

    return 0;
}
