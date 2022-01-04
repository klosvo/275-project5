//
//  DataSource.cpp
//  project4
//
//  Created by Kama Svoboda on 4/30/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

#include "DataSource.h"
#include <time.h>

DataSource::DataSource(){
    inFileName = "NoInput";
    username1 = "NoName";
    username2 = "NoName";
}

DataSource::DataSource(string input, string v1, string v2){
    inFileName = input;
    username1 = v1;
    username2 = v2;
}

string DataSource::getInputFile(){
    return inFileName;
}

//Graph* DataSource::buildGraph(){
////    Graph* g = new Graph();
////    return g;
//}

bool DataSource::readInputFile(){
    ifstream contents;
    //string delim = "   ";
    //string dummy, restOfString;
    string usr, follower;
    bool user1Exists = false;
    bool user2Exists = false;
    
    contents.open(inFileName);   // open input file
    if (contents.is_open()) {
        
        if(file_is_empty(contents)){
            return false;
        }
        
        stringstream sLine;     // declare stringstream for reading each line of the file
        string currentLine;     // declare a string to store each line as we go
        
        g = new Graph();
        
        while (!contents.eof()) {
            // if the data is good continue, else skip line
            if(contents.good()){
                // extract the line from the file and put into variable currentLine
                getline(contents, currentLine);
                if(currentLine.length() > 3){
                    
                    sLine.clear();  // clear the string stream
                    sLine.str(currentLine); // load the string stream with the currentLine
                    sLine >> usr >> follower;    // extract data from the line
                
                    if((username1 == usr) || (username1 == follower)){
                        user1Exists = true;
                    }
                    if((username2 == usr) || (username2 == follower)){
                        user2Exists = true;
                    }
                    
                    Vertex* u = new Vertex(usr);
                    Vertex* f = new Vertex(follower);
                    //Edge* e = new Edge(u, f);
                    
                    g->addVertex(u);
                    g->addVertex(f);
                    
                    Vertex* u1 = g->findVertex(usr);
                    Vertex* u2 = g->findVertex(follower);
                    u1->addFollower(u2);
                    u1->addFollowing(u2);
                    u2->addFollower(u1);
                    u2->addFollowing(u1);
                    
//                    if(g->edgeDNE(e)){
//                        g->addEdge(e);
//                    }
                }
            }else{
                return false;
            }
        }
        
        if(!user1Exists){
            cout << "Error: user " << username1 << " not found in input file " << inFileName << "." << endl;
            exit(EXIT_FAILURE);
        }else if(!user2Exists){
            cout << "Error: user " << username2 << " not found in input file " << inFileName << "." << endl;
            exit(EXIT_FAILURE);
        }
        
    }
    else{
        cout << "Could not open file " << inFileName << endl;
        // close the input file and abort
        contents.close();
        return false;
    }
    
    // If end-of-file not reached, then an error occurred
    if (!contents.eof()) {
        cout << "Error reading inputFile" << endl;
        cout << "Did not reach EOF" << endl;
        exit(EXIT_FAILURE);
        return false;
    }
    
    // Close file when done reading
    contents.close();
    return true;
}

// call to run
void DataSource::run(){
    
    if(g->getVerticesSize() > 0){
        rootUser = g->findVertex(username1);
        destUser = g->findVertex(username2);
        tree = new TreeNode(g);
        tree->Dijkstra(rootUser, destUser);
        tree->ShortestPath(rootUser, destUser);
    }
}


bool DataSource::writeOutput(){
    cout << "The Kevin Bacon path between " << username1 << " and " << username2 << " is:" << endl;
    tree->printPath();
    return true;
    
}

bool DataSource::file_is_empty(std::ifstream& inF)
{
    return inF.peek() == std::ifstream::traits_type::eof();
}

//void DataSource::printUsers(TreeNode* t){
//    t->BFS(rootUser, 0);
//}
