#include "Database.h"
#include <QApplication>
#include "login.h"
#include "User_View.h"
//#include "Admin_View.h"
#include "Admin_View.h"
#include "undergroundfloor.h"
#include "ThirdFloor.h"
#include "secondfloor.h"
#include "firstfloor_credit.h"
#include "firstfloor_general.h"
#include "Groundfloor.h"
#include "Secondfloorother.h"
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
    Login l;
    //GroundFloor g;
    //UndergroundFloor u;
    //ThirdFloor t;
    //SecondFloor s;
    //Firstfloor_general f;
    //firstfloor_credit c;
    //SecondFloorOther o;
    db.read();
    Timetable newtt;
    l.show();

    // MainGraph mg;
    // mg.addfloor(c);
    // mg.addfloor(c2);
    // Location ll(0, false, "Office", { 12,6 });
    // Location sta(0, false, "Office", { 12,47 });
    // mg.stairs.push_back(sta);
    // vector<pair<int, pair<int, int>>> ans = mg.SearchBig(0, 13, 10, ll);
    // for (auto i : ans)
    // {
    //     cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
    // }

    vector<string>emptydctrs,emptyTAs;

    newtt.day = "Sunday";
    newtt.hour = 8;
    newtt.minutes = 0;
    Schedule currsch;
    Course currcrs("Artificial Intelligence","CS",1,0,emptydctrs,emptyTAs);
    Database::CurrentUser.register_courses(currcrs.getCourseName());
    currsch.setType("Lab");
    currsch.setName("Robotics Lab");
    currsch.setCourse("Artificial Intelligence");
    Database::schedules[newtt].push_back(currsch);

    newtt.day = "Tuesday";
    newtt.hour = 2;
    newtt.minutes = 0;
    Database::schedules[newtt].push_back(currsch);
    newtt.hour = 12;
    Course currcrs2("Operation Research","IS",0,1,emptydctrs,emptyTAs);
    Database::CurrentUser.register_courses(currcrs2.getCourseName());
    currsch.setName("Class 7");
    currsch.setCourse("Operation Research");
    currsch.setType("Tutorial");
    Database::schedules[newtt].push_back(currsch);


    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
