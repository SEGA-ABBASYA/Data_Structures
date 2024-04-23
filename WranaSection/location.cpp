#include "location.h"

Location::Location()
{

}
Location::Location(string name, queue<string> doctor, bool midterm, string type, int section, bool group, map<Schedule, Course> date, string department)
{
    this->name = name;
    this->doctor = doctor;
    this->midterm = midterm;
    this->type = type;
    this->section = section;
    this->group = group;
    this->date = date;
    this->department = department;
}

//Setters
void Location::setName(string name)
{
    this->name = name;
}

void Location::setDoctor(queue<string> doctor)
{
    this->doctor = doctor;
}

void Location::setSection(int section)
{
    this->section = section;
}

void Location::setGroup(bool group)
{
    this->group = group;
}

void Location::setMidterm(bool midterm)
{
    this->midterm = midterm;
}

void Location::setType(string type)
{
    this->type = type;
}

void Location::setDepartment(string department)
{
    this->department = department;
}

void Location::setDate(map<Schedule, Course> date)
{
    this->date = date;
}


//Getters
string Location::getName()
{
    return name;
}

queue<string> Location::getDoctor()
{
    return doctor;
}

int Location::getSection()
{
    return section;
}

int Location::getGroup()
{
    return group;
}

map<Schedule, Course> Location::getDate()
{
    return date;
}

bool Location::getMidterm()
{
    return midterm;
}

string Location::getType()
{
    return type;
}

string Location::getDepartment()
{
    return department;
}


Location::~Location()
{
}
