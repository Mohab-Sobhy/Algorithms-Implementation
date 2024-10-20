//
// Created by mohab on 10/20/24.
//

#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H


struct DisjointSets
{
    int n;
    int* parent;

    void Initialize(int _n);
    void Destroy();
    int Find(int i);
    bool Union(int i, int j);
    int FindLargestSetNodes();
    void Print();
};

#endif //DISJOINTSETS_H