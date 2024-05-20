#include "Maingraph.h"
#include "Database.h"
#include <QApplication>
#include "login.h"
#include "User_View.h"
#include "Secondfloorother.h"
#include "secondfloor.h"
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
    //Login l;
    //SecondFloor S;
    //SecondFloorOther o;
    UserView u;
    u.show();
    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
