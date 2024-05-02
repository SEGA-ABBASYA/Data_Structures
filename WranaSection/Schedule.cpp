#include "Schedule.h"

Timetable Schedule::getDate()
{
    return date;
}

string Schedule::getName()
{
    return name;
}

Schedule::Schedule()
{

}
Schedule::Schedule(string name, queue<string> doctor, bool midterm, string type, int section, bool group,Timetable date,Course course ,string department)
{
    this->name = name;
    this->doctor = doctor;
    this->midterm = midterm;
    this->type = type;
    this->section = section;
    this->group = group;
    this->date = date;
    this->department = department;
    this->course = course;
}

//Setters
void Schedule::setName(string name)
{
    this->name = name;
}

void Schedule::setDoctor(queue<string> doctor)
{
    this->doctor = doctor;
}

void Schedule::setSection(int section)
{
    this->section = section;
}

void Schedule::setGroup(bool group)
{
    this->group = group;
}

void Schedule::setMidterm(bool midterm)
{
    this->midterm = midterm;
}

void Schedule::setType(string type)
{
    this->type = type;
}

void Schedule::setDepartment(string department)
{
    this->department = department;
}

void Schedule::setDate(Timetable date)
{
    this->date = date;
}



void Schedule::setCourse(Course newCourse)
{
    course = newCourse;
}

//Getters
Course Schedule::getCourse()
{
    return course;
}


queue<string> Schedule::getDoctor()
{
    return doctor;
}

int Schedule::getSection()
{
    return section;
}

int Schedule::getGroup()
{
    return group;
}



bool Schedule::getMidterm()
{
    return midterm;
}

string Schedule::getType()
{
    return type;
}

string Schedule::getDepartment()
{
    return department;
}


Schedule::~Schedule()
{
}
