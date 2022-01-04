//
//  TreeNode.hpp
//  project4
//
//  Created by Kama Svoboda on 4/30/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h

#include "Vertex.h"
#include "Graph.h"

#include <stdio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

// TreeNode -- Should have a constructor to take in the Vertex (pointer), and the depth of that vertex in the tree (by default, 0 if it is the root of the tree). As more Vertex objects are added to the tree through the methods you choose, the depth of the tree should grow.

class TreeNode {
public:
    TreeNode();
    TreeNode(Graph* graph);
    ~TreeNode( ) { }
//    void RecursiveDFS(Vertex* v, int depth);
//    void BFS(Vertex* v, int depth);
    set<Vertex*, alphabetical> alphabetizeFollowers(Vertex* v);
    void Dijkstra(Vertex* startV, Vertex* endV);
    void ShortestPath(Vertex* startV, Vertex* endV);
    void printPath();
    priority_queue<Vertex*, vector<Vertex*>, minDist> updateUnvisited(priority_queue<Vertex*, vector<Vertex*>, minDist> old);
private:
//    int depth;
    vector<Vertex*> path;
    Graph* g;
};

#endif /* TreeNode_h */
