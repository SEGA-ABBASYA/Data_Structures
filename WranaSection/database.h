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
#include "Maingraph.h"
class Database
{

public:
    static QMap<string, User> users;
    static map<string, Location> locations;
    static map<Timetable, vector<Schedule>> schedules;
    static Admin admin;
    static map<string,Course> courses;
    static vector<string>UnderGroundFloor;
    static vector<string>GroundFloor;
    static vector<string>FirstGeneralFloor;
    static vector<string>FirstCreditFloor;
    static vector<string>SecondFloor;
    static vector<string>SecondOtherFloor;
    static vector<string>ThirdFloor;
    static vector<string>SecondFloorMerged;
    static vector<string>FirstFloorMerged;
    static MainGraph mg;


    Database();
    void read();
    void write();

private:
    QFile usersFile, locationsFile, adminFile, CoursesFile, schedulesFile;
    QFile UnderGroundFile,GroundFile,FirstGeneralFile,FirstCreditFile,SecondFile,SecondOtherFile,ThirdFile,SecondMFile,FirstMFile;
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

    void Read_UnderGroundFloor();
    void Read_GroundFloor();
    void Read_FirstGeneralFloor();
    void Read_FirstCreditFloor();
    void Read_SecondFloor();
    void Read_SecondOtherFloor();
    void Read_ThirdFloor();
    void Read_SecondMFloor();
    void Read_FirstMFloor();

    void mgIntialization();
};

#endif // DATABASE_H
