#ifndef ADMIN_H
#define ADMIN_H
#include "course.h"
#include "location.h"
#include <bits/stdc++.h>
using namespace std;
class Admin
{

private:

    string username;
    string password;

public:

    // Constructor
    Admin();

    // Getter, and setter for username.
    string getUsername();
    void setUsername(string newUsername);

    // Getter, and setter for password.
    string getPassword();
    void setPassword(string newPassword);

    // Course class related methods.
    void editCourse(Course course);
    void addCourse(Course course);
    void deleteCourse(Course course);

    // Loction class related methods.
    void addLocation(Location location);
    void editLocation(Location location);
    void removeLocation(Location location);

    void mangoElAb();

    // Destructor
    ~Admin();
};

#endif // ADMIN_H
