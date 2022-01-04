//
//  TreeNode.cpp
//  project4
//
//  Created by Kama Svoboda on 4/30/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

#include "TreeNode.h"


TreeNode::TreeNode(){
}

TreeNode::TreeNode(Graph* graph){
    g = graph;
}

//set<Vertex*, alphabetical> TreeNode::alphabetizeFollowers(Vertex* v){
//    set<Vertex*> s = v->getFollowers();
//    std::set<Vertex*, alphabetical>::iterator j = s.begin();
//    set<Vertex*, alphabetical> abc;
//    while(j != s.end()){
//        abc.insert(*j);
//        j++;
//    }
//    return abc;
//}




void TreeNode::Dijkstra(Vertex* startV, Vertex* endV) {
    
    int altPathDistance, edgeWeight;
    Vertex* currentV;
    //queue<Vertex*> unvisitedQ;
    priority_queue<Vertex*, vector<Vertex*>, minDist> unvisitedQ;
    //set<Vertex*> s = startV->getFollowers();
    set<Vertex*> s = g->getVertices();
    //set<Vertex*, alphabetical> s = g->getVertices();
    std::set<Vertex*>::iterator j = s.begin();
    //std::set<Vertex*, alphabetical>::iterator j = s.begin();
    
    while(j != s.end()){
        //cout << (*j)->getName()<< endl;
        (*j)->setDistance(INT_MAX);
        (*j)->setPredecessor(nullptr);
        unvisitedQ.push(*j);
        j++;
    }
    // startV has a distance of 0 from itself
    startV->setDistance(0);
    edgeWeight = 1;
    unvisitedQ = updateUnvisited(unvisitedQ);
    while (!unvisitedQ.empty() && (unvisitedQ.top()->getDistance() < 200000)) {
        // Visit vertex with minimum distance from startV
        currentV = unvisitedQ.top();
        if(currentV->getName() == endV->getName()){
            return;
        }
        unvisitedQ.pop();
        set<Vertex*> adjV = currentV->getFollowers();
        //set<Vertex*, alphabetical> adjV = alphabetizeFollowers(currentV);
        std::set<Vertex*>::iterator j = adjV.begin();
        while(j != adjV.end()){
            altPathDistance = currentV->getDistance() + edgeWeight;
            
            // If shorter path from startV to adjacentV is found,
            // update adjacentV's distance and predecessor
            if (altPathDistance < (*j)->getDistance()) {
                (*j)->setDistance(altPathDistance);
                (*j)->setPredecessor(currentV);
            }else if(altPathDistance == (*j)->getDistance()){
                if((*j)->getName() < currentV->getName()){
                    (*j)->setPredecessor(currentV);
                }
            }
            j++;
        }
        unvisitedQ = updateUnvisited(unvisitedQ);
    }
}

priority_queue<Vertex*, vector<Vertex*>, minDist> TreeNode::updateUnvisited(priority_queue<Vertex*, vector<Vertex*>, minDist> old){
    priority_queue<Vertex*, vector<Vertex*>, minDist> newQ;
    Vertex* temp;
    
    while (!old.empty()){
        temp = old.top();
        old.pop();
        newQ.push(temp);
    }
    
    return newQ;
}


void TreeNode::ShortestPath(Vertex* startV, Vertex* endV){
    Vertex* currentV = endV;
    
    while(currentV->getPredecessor() != nullptr){
        path.push_back(currentV);
        currentV = currentV->getPredecessor();
    }
    path.push_back(currentV);
}

void TreeNode::printPath(){
    //std::set<Vertex*>::iterator i = path.at(0);
    int i;
    for(i = (int)path.size()-1; i > 0 ; i--){
        cout << path.at(i)->getName() << endl;
    }
    cout << path.at(i)->getName() << endl;
}
