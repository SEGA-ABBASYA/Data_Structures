#include "Maingraph.h"
#include "Database.h"
#include <QApplication>
#include "login.h"
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
    db.read();
    Login l;
    //GroundFloor g;
    //UndergroundFloor u;
    //ThirdFloor t;
    //SecondFloor s;
    //Firstfloor_general f;
    //firstfloor_credit c;
    //SecondFloorOther o;
    //ThirdFloor th;
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


    l.show();
    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
