#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <string>
#include "course.h"
#include <queue>
#include <map>
using namespace std;

struct Timetable{
    int hour;
    int minutes;
    string day;
};
class Schedule
{
    //refers to location
    string name;

    //teaching this lab or lecture
    queue<string> doctor;

    //if there are two doctors one before mid and another after
    //0 before, 1 after
    bool midterm;

    //Lab, section or lecture
    string type;

    int section;

    //0 for G1 , 1 for G2
    bool group;

    //Mainstream for years 1,2 and from years 3,4 (CS, IS, SC, CSYS)
    string department;


    // Day, Hour and minutes
    map<Timetable, Course> date;

public:
    Schedule();
    Schedule(string, queue<string>, bool, string, int, bool, map<Timetable, Course>, string);

    void setName(string);
    void setDoctor(queue<string>);
    void setSection(int);
    void setGroup(bool);
    void setDate(map<Timetable, Course>);
    void setMidterm(bool);
    void setType(string);
    void setDepartment(string);


    string getName();
    queue<string> getDoctor();
    int getSection();
    int getGroup();
    map<Timetable, Course> getDate();
    bool getMidterm();
    string getType();
    string getDepartment();

    ~Schedule();

};

#endif // SCHEDULE_H
