#ifndef DATABASE_H
#define DATABASE_H
#include"Admin.h"
#include <map>
#include <fstream>
#include "user.h"
#include "location.h"
#include "Schedule.h"
#include <QString>
#include <QFile>
#include <QMap>
#include <vector>
class Database
{

public:
    static QMap<string, User> users;
    static map<string, Location> locations;
    static map<Timetable, vector<Schedule>> schedules;
    static Admin admin;
    static map<string,Course> courses;

    Database();
    void read();
    void write();

private:
    QFile usersFile, locationsFile, adminFile, CoursesFile, schedulesFile;
    void readUsers();
    void readLocations();
    void writeUsers();
    void writeLocations();
    void readSchedule();
    void writeSchedule();
    void ReadAdmin();
    void WriteAdmin();
    void ReadCourses();
    void WriteCourses();


};

#endif // DATABASE_H
