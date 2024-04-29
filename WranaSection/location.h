#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include "course.h"
#include <queue>
#include <map>
using namespace std;

<<<<<<< Updated upstream:WranaSection/location.h
struct Schedule{
    int hours;
=======
struct Timetable {
    int hour;
>>>>>>> Stashed changes:WranaSection/Schedule.h
    int minutes;
    std::string day;

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
class Location
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


    // Day, Hour and minutes
    Timetable date;

    //Course Object;
    Course course;

    //Mainstream for years 1,2 and from years 3,4 (CS, IS, SC, CSYS)
    string department;

<<<<<<< Updated upstream:WranaSection/location.h

    // Day, Hours and minutes
    map<Schedule, Course> date;

public:
    Location();
    Location(string, queue<string>, bool, string, int, bool, map<Schedule, Course>, string);
=======
public:
    Schedule();
    Schedule(string, queue<string>, bool, string, int, bool, Timetable, Course, string);
>>>>>>> Stashed changes:WranaSection/Schedule.h

    void setName(string);
    void setDoctor(queue<string>);
    void setSection(int);
    void setGroup(bool);
<<<<<<< Updated upstream:WranaSection/location.h
    void setDate(map<Schedule, Course>);
=======
>>>>>>> Stashed changes:WranaSection/Schedule.h
    void setMidterm(bool);
    void setType(string);
    void setDepartment(string);


    string getName();
    queue<string> getDoctor();
    int getSection();
    int getGroup();
<<<<<<< Updated upstream:WranaSection/location.h
    map<Schedule, Course> getDate();
=======
>>>>>>> Stashed changes:WranaSection/Schedule.h
    bool getMidterm();
    string getType();
    string getDepartment();

    ~Location();

    Course getCourse() const;
    void setCourse(const Course &newCourse);
    Timetable getDate() const;
    void setDate(const Timetable &newDate);
};

#endif // LOCATION_H
