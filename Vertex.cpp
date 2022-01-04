//
//  Vertex.cpp
//  project4
//
//  Created by Kama Svoboda on 4/30/20.
//  Copyright © 2020 Kama Svoboda. All rights reserved.
//

#include "Vertex.h"

Vertex::Vertex(){
    name = "NONAME";
    position = -1;
}

Vertex::Vertex(string usr){
    name = usr;
    position = -1;
}

string Vertex::getName(){
    return name;
}

bool Vertex::followerDNE(string f){
    std::set<Vertex*>::iterator i = followers.begin();
    while(i != followers.end()){
        if((*i)->getName() == f){
            return false;
        }
        i++;
    }
    return true;
}

bool Vertex::followingDNE(string f){
    std::set<Vertex*>::iterator i = following.begin();
    while(i != following.end()){
        if((*i)->getName() == f){
            return false;
        }
        i++;
    }
    return true;
}

void Vertex::addFollower(Vertex* v){
    if(followerDNE(v->getName())){
        followers.insert(v);
    }
}

void Vertex::addFollowing(Vertex* v){
    if(followingDNE(v->getName())){
        following.insert(v);
    }
}

int Vertex::getFollowerSize(){
    return (int)followers.size();
}

int Vertex::getFollowingSize(){
    return (int)following.size();
}

set<Vertex*> Vertex::getFollowers(){
    return followers;
}

int Vertex::getPosition(){
    return position;
}

void Vertex::setPosition(int n){
    position = n;
}

void Vertex::setFollowers(set<Vertex*> s){
    followers.clear();
    followers = s;
}

void Vertex::setDistance(int n){
    distance = n;
}

void Vertex::setPredecessor(Vertex* v){
    predecessor = v;
}

int Vertex::getDistance(){
    return distance;
}

Vertex* Vertex::getPredecessor(){
    return predecessor;
}
