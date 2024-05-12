#include "Maingraph.h"
#include "Database.h"
#include <QApplication>
#include "login.h"
#include "User_View.h"
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


    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
