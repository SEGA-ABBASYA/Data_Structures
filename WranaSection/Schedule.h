#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <string>
#include "course.h"
#include <queue>
#include <map>
using namespace std;

struct Timetable {
    int hour;
    int minutes;
    string day;

    // Define less than operator for Timetable
    bool operator<(const Timetable& other) const {
        // Compare days first
        if (day < other.day)
            return true;
        if (day > other.day)
            return false;

        // If days are equal, compare hours
        if (hour < other.hour)
            return true;
        if (hour > other.hour)
            return false;

        // If days and hours are equal, compare minutes
        return minutes < other.minutes;
    }
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
    Timetable date;
    Course course;

public:
    Schedule();
    Schedule(string, queue<string>, bool, string, int, bool,Timetable, Course, string);

    void setName(string);
    void setDoctor(queue<string>);
    void setSection(int);
    void setGroup(bool);
    void setDate(Timetable);
    void setMidterm(bool);
    void setType(string);
    void setDepartment(string);
    void setCourse(Course newCourse);

    Course getCourse();

    queue<string> getDoctor();
    int getSection();
    int getGroup();
    Timetable getDate();
    bool getMidterm();
    string getType();
    string getDepartment();
    string getName();

    ~Schedule();





};

#endif // SCHEDULE_H
