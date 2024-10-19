//
// Created by mohab on 10/19/24.
//

#ifndef NODE_H
#define NODE_H
#include "../Array.h"

struct Node
{
    Array<int> adj;

    void Initialize();
    void Destroy();
};

#endif //NODE_H
