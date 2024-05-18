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
#include "Secondfloorother.h"
#include "undergroundfloor.h"
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
    UndergroundFloor u;
    //ThirdFloor t;
    //SecondFloor s;
    //Firstfloor_general f;
    //firstfloor_credit c;
    //SecondFloorOther o;
    //ThirdFloor th;
    u.show();

    Location ll(4, false, "Office", { 22,57 });
    vector<pair<int, pair<int, int>>> ans = Database::mg.SearchBig(0, 22, 62, ll);
    for (auto i : ans)
    {

        //ui->tableWidget->setItem(i.second.first, i.second.second, new QTableWidgetItem);
        //ui->tableWidget->item(i.second.first, i.second.second)->setBackground(Qt::red);
        cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
    }


    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
