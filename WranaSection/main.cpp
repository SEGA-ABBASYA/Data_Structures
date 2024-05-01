#include "Admin_View.h"
#include"Database.h"
#include <QApplication>
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
    AdminView w;
    w.show();
    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
