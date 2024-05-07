#include <iostream>
#include <vector>
#include <string>
#include"Admin.h"
#include"database.h"
using namespace std;

// Object of Database class
Database db;

// Constructor
Admin::Admin()
{
    username = "Admin";
    password = "Admin"; 
}

// Getter, and setter for username.
string Admin::getUsername()
{
    return username;
}
void Admin::setUsername(string newUsername)
{
    username = newUsername;
}

// Getter, and setter for password.
string Admin::getPassword()
{
    return password;
}
void Admin::setPassword(string newPassword)
{
    password = newPassword;
}

// Course class related methods.
void Admin::editCourse(Course course)
{
    // Body
}
void Admin::addCourse(Course course)
{
    /* the [] operator handels if the object has the same key
     and overwrites the existing one.*/
    db.courses[course.getCourseName()] = course;
}
void Admin::deleteCourse(string courseName)
{
    db.courses.erase(courseName);
}

// Loction class related methods.
void Admin::editLocation(Location location)
{
    // Body
}

// user related methods.
void Admin::addUser(User user)
{
    // Body
}
void Admin::editUser(User user)
{
    // Body
}
void Admin::deleteUser(User user)
{
    // Body
}

// Destructor
Admin::~Admin()
{

}
