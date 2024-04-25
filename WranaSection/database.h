#ifndef DATABASE_H
#define DATABASE_H
#include"Admin.h"
#include<map>
#include<fstream>
class Database
{

public:
    Database();
    Admin admin;
    map<string,Course>courses;

   void read();
   void write();

private:

     void ReadAdmin();
      void WriteAdmin();

    void ReadCourses();
     void WriteCourses();


};

#endif // DATABASE_H
