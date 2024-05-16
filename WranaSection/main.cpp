#include "Database.h"
#include <QApplication>
#include "login.h"
#include "User_View.h"
//#include "Admin_View.h"
using namespace std;
void write()
{
    Database data;
    data.write();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database db;
    Login w;
    db.read();
    w.show();
    Timetable newtt;


    newtt.day = "Sunday";
    newtt.hour = 8;
    newtt.minutes = 0;
    Schedule currsch;
    Course currcrs;
    currcrs.setCourseName("Artificial Intelligence Lab");
    currsch.setCourse(currcrs);
    Database::schedules["Lab 6"][newtt] = currsch;


    newtt.day = "Tuesday";
    newtt.hour = 12;
    newtt.minutes = 0;
    currcrs.setCourseName("Artificial Intelligence Lab");
    currsch.setCourse(currcrs);
    Database::schedules["Robotics Lab"][newtt] = currsch;

    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
