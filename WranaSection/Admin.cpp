#include <iostream>
#include <vector>
#include"Admin.h"

using namespace std;

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
    // Body
}
void Admin::deleteCourse(Course course)
{
    // Body
}

// Loction class related methods.
void Admin::addLocation(Location location)
{
    // Body
}
void Admin::editLocation(Location location)
{
    // Body
}
void Admin::removeLocation(Location location)
{
    // Body
}

void Admin::mangoElAb()
{
    cout << "Mango world";
}

// Destructor
Admin::~Admin()
{

}
