#include "Location.h"

Location::Location() {}

Location::Location(int floor, bool hall, string name, pair<int, int> node){
    this->floor = floor;
    this->hall = hall;
    this->name = name;
    this->node = node;
}

//Setters

void Location::setFloor(int floor){
    this->floor = floor;
}

void Location::setHall(bool hall){
    this->hall = hall;
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
    return hall;
}

string Location::getName(){
    return name;
}

pair<int, int> Location::getNode(){
    return node;
}



Location::~Location(){}
