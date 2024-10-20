//
// Created by mohab on 10/20/24.
//

#include "../header/DisjointSets.h"
#include <iostream>
using namespace std;

void DisjointSets::Initialize(int _n) {
    n = _n;
    parent = new int [n];
    for(int i=0; i<n ; i++) {
        parent[i] = -1;
    }
}

void DisjointSets::Destroy() {
    delete [] parent;
    parent = nullptr;
}

int DisjointSets::Find(int i) {
    if (parent[i] < 0) {
        return i;
    }
    else {
        parent[i] = Find(parent[i]); // Path compression
        return parent[i];
    }
}


bool DisjointSets::Union(int i, int j) {
    if(Find(i) == Find(j)) {
        return false;
    }
    else {
        if( parent[Find(i)] < parent[Find(j)] ) {
            parent[Find(i)] += parent[Find(j)];
            parent[Find(j)] = Find(i);
        }
        else {
            parent[Find(j)] += parent[Find(i)];
            parent[Find(i)] = Find(j);
        }
        return true;
    }
}

int DisjointSets::FindLargestSetNodes() {
    int smalest = parent[Find(1)];
    for(int i=1;i<n;i++) {
        if(smalest > parent[Find(i)]) {
            smalest = parent[Find(i)];
        }
    }
    return -1 * smalest;
}

void DisjointSets::Print() {
    for(int i=0;i<n;i++) {
        cout<<parent[i]<<' ';
    }
}