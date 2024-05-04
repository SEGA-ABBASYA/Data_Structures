#include "mainwindow.h"
#include"Database.h"
#include "newuser.h"
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
    NewUser w;
    w.show();
    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
