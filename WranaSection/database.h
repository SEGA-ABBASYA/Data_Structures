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

class Database
{

public:
    QVector<User> users;
    QMap<QString, Location> locations;
    QMap<string, QMap<Timetable, Schedule>> schedules;
    QString currentUserEmail;
    Database();
    Admin admin;
    map<string,Course>courses;

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
