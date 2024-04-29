#include "Schedule.h"

Course Schedule::getCourse() const
{
    return course;
}

void Schedule::setCourse(const Course &newCourse)
{
    course = newCourse;
}

Timetable Schedule::getDate() const
{
    return date;
}

void Schedule::setDate(const Timetable &newDate)
{
    date = newDate;
}

Schedule::Schedule()
{

}
Schedule::Schedule(string name, queue<string> doctor, bool midterm, string type, int section, bool group, Timetable date, Course course, string department)
{
    this->name = name;
    this->doctor = doctor;
    this->midterm = midterm;
    this->type = type;
    this->section = section;
    this->group = group;
    this->date = date;
    this->course = course;
    this->department = department;
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


//Getters
string Schedule::getName()
{
    return name;
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
