//
//  DataSource.hpp
//  project4
//
//  Created by Kama Svoboda on 4/30/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

#ifndef DataSource_h
#define DataSource_h

#include <stdio.h>
#include <string.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

#include "Graph.h"
#include "TreeNode.h"
#include "Vertex.h"
#include "Edge.h"


// DataSource -- Construct through a filename, and call a method named buildGraph which returns a pointer to a Graph that is created from the file.

using namespace std;

class DataSource {
public:
    DataSource();
    DataSource(string filename, string v1, string v2);
    ~DataSource( ) { }
    bool readInputFile();
    void run();
    bool writeOutput();
    bool file_is_empty(std::ifstream& inF);
    string getInputFile();
    //Graph* buildGraph();
    set<Vertex*> findD2Users(Vertex* v);
//    void printUsers(TreeNode* t);
private:
    Graph* g;
    string inFileName;
    Vertex* rootUser;
    Vertex* destUser;
    TreeNode* tree;
    string username1;
    string username2;
    Vertex* vertex1;
    Vertex* vertex2;
};

#endif /* DataSource_h */
