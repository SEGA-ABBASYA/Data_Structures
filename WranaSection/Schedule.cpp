#include "Schedule.h"

Timetable Schedule::getDate()
{
    return date;
}

string Schedule::getName()
{
    return name;
}

string Schedule::getCourse() const
{
    return course;
}

void Schedule::setCourse(const string &newCourse)
{
    course = newCourse;
}

Schedule::Schedule()
{

}
Schedule::Schedule(string name, string type, int section, bool group,Timetable date,string course)
{
    this->name = name;
    this->type = type;
    this->section = section;
    this->group = group;
    this->date = date;
    this->course = course;
}

//Setters
void Schedule::setName(string name)
{
    this->name = name;
}

void Schedule::setSection(int section)
{
    this->section = section;
}

void Schedule::setGroup(bool group)
{
    this->group = group;
}

void Schedule::setType(string type)
{
    this->type = type;
}

void Schedule::setDate(Timetable date)
{
    this->date = date;
}

//Getters
int Schedule::getSection()
{
    return section;
}

int Schedule::getGroup()
{
    return group;
}

string Schedule::getType()
{
    return type;
}

Schedule::~Schedule()
{
}
