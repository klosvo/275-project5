//
//  Graph.cpp
//  project4
//
//  Created by Kama Svoboda on 4/30/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

#include "Graph.h"

Graph::Graph(){
}

//Graph::Graph(Vertex* v, Edge* e){
//    vertices.insert(v);
//    edges.insert(e);
//}

Vertex* Graph::findVertex(string username){
    std::set<Vertex*>::iterator i = vertices.begin();
    while(i != vertices.end()){
        if((*i)->getName() == username){
            return (*i);
        }
        i++;
    }
    return nullptr;
}

//void Graph::printVertices(){
//    cout << endl << endl << "THE VERTICES ARE: " << endl;
//    std::set<Vertex*>::iterator i = vertices.begin();
//    while(i != vertices.end()){
//        cout << (*i)->getName() << endl;
//        i++;
//    }
//}

void Graph::addVertex(Vertex* v){
    if(vertexDNE(v)){
        vertices.insert(v);
    }
}

//void Graph::addEdge(string src, string dst){
//    Edge* e = new Edge(findVertex(src), findVertex(dst));
//    edges.insert(e);
//}
//
//void Graph::addEdge(Edge* e){
//    edges.insert(e);
//}
//
//void Graph::addEdge(Vertex* src, Vertex* dst){
//    Edge* e = new Edge(src, dst);
//    edges.insert(e);
//}


bool Graph::vertexDNE(Vertex* v){
    std::set<Vertex*>::iterator i = vertices.begin();
    while(i != vertices.end()){
        if((*i)->getName() == v->getName()){
            return false;
        }
        i++;
    }
    return true;
}

//bool Graph::edgeDNE(Edge* e){
//    std::set<Edge*>::iterator i = edges.begin();
//    while(i != edges.end()){
//        if((*i)->getSource()->getName() == e->getSource()->getName())
//            if((*i)->getDest()->getName() == e->getDest()->getName())
//                return false;
//        i++;
//    }
//    return true;
//}

Vertex* Graph::findMaxFollowers(){
    std::set<Vertex*>::iterator i = vertices.begin();
    int maxFollowers = 0;
    Vertex* ptoMax = (*i);
    while(i != vertices.end()){
        if((*i)->getFollowerSize() > maxFollowers){
            maxFollowers = (*i)->getFollowerSize();
            ptoMax = (*i);
        }else if((*i)->getFollowerSize() == maxFollowers){
            if(ptoMax->getName() > (*i)->getName()){
                ptoMax = (*i);
            }
        }
        i++;
    }
    return ptoMax;
}

int Graph::getVerticesSize(){
    return (int)vertices.size();
}


int Graph::inDegreeCentrality(Vertex* v){
    return v->getPosition();
}

set<Vertex*> Graph::getVertices(){
    return vertices;
}
