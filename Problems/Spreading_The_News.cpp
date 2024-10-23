#include <iostream>
#include "../DataStructures/header/Graph/Graph.h"
#include "../DataStructures/header/Queue.h"
using namespace std;

int Spreading_The_News() {
    int numOfEmployees;
    Graph employees;
    cin >> numOfEmployees;
    employees.Initialize(numOfEmployees);

    for(int i = 0; i < numOfEmployees; i++) {
        int numOfEmpFriends;
        cin >> numOfEmpFriends;

        for(int j = 0; j < numOfEmpFriends; j++) {
            int friendIndex;
            cin >> friendIndex;
            employees.nodes[i].adj.AddLast(friendIndex);
        }
    }

    int testCases;
    cin >> testCases;

    while(testCases--) {
        int firstEmpKnowsNews;
        int dayOfKnowing[numOfEmployees];
        Queue<int> q;
        q.Initialize(numOfEmployees);

        for(int i = 0; i < numOfEmployees; i++) {
            dayOfKnowing[i] = -1;
        }

        cin >> firstEmpKnowsNews;
        q.Add(firstEmpKnowsNews);
        dayOfKnowing[firstEmpKnowsNews] = 0;

        int day = 0;
        while (q.Num() > 0) {
            int size = q.Num();
            for (int j = 0; j < size; j++) {
                int currentEmpIndex = q.Pop();
                for(int i = 0; i < employees.nodes[currentEmpIndex].adj.getNumOfElements(); i++) {//loop for
                    int friendIndex = employees.nodes[currentEmpIndex].adj[i];
                    if(dayOfKnowing[friendIndex] == -1) {
                        dayOfKnowing[friendIndex] = day + 1;
                        q.Add(friendIndex);
                    }
                }
            }
            day++;
        }

        int repetations[numOfEmployees];
        for(int i=0 ; i<numOfEmployees ; i++) {
            repetations[i]=0;
        }
        for(int i=0 ; i<numOfEmployees ; i++) {
            repetations[dayOfKnowing[i]]++;
        }
        int maxEmpKnowing=-1;
        int dayOfMaxEmpKnowing;
        for(int i=0 ; i<numOfEmployees ; i++) {
            if(repetations[i]>maxEmpKnowing) {
                maxEmpKnowing=repetations[i];
                dayOfMaxEmpKnowing = i;
            }
        }

        if(dayOfMaxEmpKnowing==0) {
            cout<<0<<endl;
        }
        else {
            cout<<maxEmpKnowing<<' '<<dayOfMaxEmpKnowing<<endl;
        }

    }

    return 0;
}
