//
//  Vertex.hpp
//  project4
//
//  Created by Kama Svoboda on 4/30/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

// Vertex -- represent nodes in the graph, presents methods to get edges that come in, and that go out, as well as vertices that are connected through incoming (and outgoing) edges.

#ifndef Vertex_h
#define Vertex_h

#include <stdio.h>
#include <string>
#include <limits.h>
#include <stdlib.h>
#include <set>

using namespace std;

class Vertex {
public:
    Vertex();
    Vertex(string usr);
    ~Vertex( ) { }
    string getName();
    void addFollower(Vertex* v);
    void addFollowing(Vertex* v);
    int getFollowerSize();
    int getFollowingSize();
    void setPosition(int n);
    void setFollowers(set<Vertex*> s);
    set<Vertex*> getFollowers();
    int getPosition();
    void setDistance(int n);
    int getDistance();
    void setPredecessor(Vertex* v);
    Vertex* getPredecessor();
    bool followerDNE(string f);
    bool followingDNE(string f);
private:
    string name;
    set<Vertex*> followers;
    set<Vertex*> following;
    int position;
    int distance;
    Vertex* predecessor;

};

struct alphabetical {
    bool operator() (Vertex* lhs, Vertex* rhs) const{
        string a = lhs->getName();
        string b = rhs->getName();
        a.at(0) = tolower(a.at(0));
        b.at(0) = tolower(b.at(0));
    return a < b;}
};

struct minDist {
    bool operator() (Vertex* lhs, Vertex* rhs) const{
        int a = lhs->getDistance();
        int b = rhs->getDistance();
        return a > b;}
};

#endif /* Vertex_h */
