//
//  Graph.hpp
//  project4
//
//  Created by Kama Svoboda on 4/30/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include "Vertex.h"
#include "Edge.h"

// Graph -- abstraction to maintain a list of Vertices and to connect vertices by adding edges. Should have methods to find a vertex (by providing its name), and to add an edge (by providing the src and dst names). Many other methods may be useful, and are up to you.
using namespace std;

class Graph {
public:
    Graph();
    //Graph(Vertex* v, Edge* e);
    ~Graph( ) { }
    void addVertex(Vertex* v);
    void addEdge(string src, string dst);
    //void addEdge(Edge* e);
    //void addEdge(Vertex* src, Vertex* dst);
    Vertex* findVertex(string username);
    bool vertexDNE(Vertex* v);
   // bool edgeDNE(Edge* e);
    Vertex* findMaxFollowers();
    int getVerticesSize();
//    void printVertices();
    int inDegreeCentrality(Vertex* v);
    set<Vertex*> getVertices();
private:
    set<Vertex*> vertices;
//    set<Edge*> edges;
};

#endif /* Graph_h */
