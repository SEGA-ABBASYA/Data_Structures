#include "Location.h"

Location::Location() {}

Location::Location(int floor, bool occupied, string name, pair<int, int> node){
    this->floor = floor;
    this->occupied = occupied;
    this->name = name;
    this->node = node;
}

//Setters

void Location::setFloor(int floor){
    this->floor = floor;
}

void Location::setHall(bool occupied){
    this->occupied = occupied;
}

void Location::setName(string name){
    this->name = name;
}

void Location::setNode(pair<int, int> node){
    this->node = node;
}

//Getters

int Location::getFloor(){
    return floor;
}

bool Location::getHall(){
    return occupied;
}

string Location::getName(){
    return name;
}

pair<int, int> Location::getNode(){
    return node;
}



Location::~Location(){}
