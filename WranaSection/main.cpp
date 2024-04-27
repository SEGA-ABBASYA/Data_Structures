#include "mainwindow.h"
#include"Database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database db;

    db.write();

    db.read();
    MainWindow w;
    w.show();
    return a.exec();
}
