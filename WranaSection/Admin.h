#pragma once
#include <string>
#include "course.h"
#include "location.h"
#include "user.h"

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
    void deleteCourse(string courseName);

    // Loction/Graph class related methods.
    void editLocation(Location location);

    // user related methods.
    void addUser (User user);
    void editUser (User user);
    void deleteUser(string username);

    // Destructor
    ~Admin();
};

