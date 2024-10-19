//
// Created by mohab on 10/19/24.
//

#ifndef GRAPH_H
#define GRAPH_H
#include "./Node.h"

struct Graph
{
    int n;
    Node* nodes;

    void Initialize(int _n);
    void Destroy();
};

#endif //GRAPH_H
