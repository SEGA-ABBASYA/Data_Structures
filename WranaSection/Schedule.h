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

    // Define equal than operator for Timetable
    bool operator==(const Timetable& other) const {
        return day==other.day && hour == other.hour && minutes==other.minutes;
    }
};
class Schedule
{
    //refers to location
    string name = "None";

    //Lab, section or lecture
    string type;

    int section;

    //0 for G1 , 1 for G2
    bool group;


    // Day, Hour and minutes
    Timetable date;
    string course;

public:
    Schedule();
    Schedule(string, string, int, bool,Timetable, string);

    void setName(string);
    void setSection(int);
    void setGroup(bool);
    void setDate(Timetable);
    void setType(string);


    int getSection();
    int getGroup();
    Timetable getDate();
    string getType();
    string getName();

    //define equal operator for schedule
    bool operator==(const Schedule& other)
    const {
        return name == other.name && section == other.section && course == other.course && type == other.type && group == other.group
               && date == other.date;
    }

    ~Schedule();





    string getCourse() const;
    void setCourse(const string &newCourse);
};

#endif // SCHEDULE_H
