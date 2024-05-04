#include "User_View.h"
#include "user.h"
#include"Database.h"
#include <QApplication>
void write()
{
    Database data;
    data.write();
}
int main(int argc, char *argv[])
{

    //string& name, int& id, int& academic_year, int& section, string& username, string& password, string& program, char& gender
    QApplication a(argc, argv);
    User alice("Alice", 2022170242 , 2 , 10 , "alica" , "alica222","Mainstream",'F');
    User bob("Bob",2022170240 , 2 , 12 , "bobs" , "bobs222","Mainstream",'M');
    User charlie("Charlie", 2022170241 , 2 , 11 , "chocho" , "chocho222","Mainstream",'F');
    alice.add_friend(&bob);
    alice.add_friend(&charlie);
    alice.printMap();
    alice.remove_friend(bob.getUsername());
    alice.remove_friend(charlie.getUsername());
    Database db;
    db.read();
    UserView w;
    w.show();
    QObject::connect(&a, &QCoreApplication::aboutToQuit, write);
    return a.exec();
}
