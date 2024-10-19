//
// Created by mohab on 10/19/24.
//

#include "../../header/Graph/Graph.h"

void Graph::Initialize(int _n) {
    n = _n;
    nodes = new Node [n];
    for(int i=0 ; i<n ; i++) {
        nodes[i].Initialize();
    }
}

void Graph::Destroy() {
    for(int i=0 ; i<n ; i++) {
        nodes[i].Destroy();
    }
    delete [] nodes;
}

