#ifndef DSCODE_USER_H
#define DSCODE_USER_H
#include "course.h"
#include "location.h"
#include<iostream>
#include<unordered_map>

struct userData {
    string name;
    int id;
    int academic_year; // 1 2 3 4
    int section;
    string user_name;
    string password;
    string program; // Mainstream or AI or SoftwareEng etc...
    char gender; // M or F
};

class User {
private:
    userData data;
    unordered_map<string, Course> registered_courses;
    unordered_map<string, Location> current_location;

public:
    // Constructor
    User(string& name, int& id, int& academic_year, int& section, string& username, string& password, string& program, char& gender);

    // Setters
    void setName(string& name);

    void setId(int id);

    void setAcademicYear(int year);

    void setSection(int& section);

    void setUsername(string& username);

    void setPassword(string& password);

    void setProgram(string& program);

    void setGender(char gender);


    // Getters
    string getName();

    int getId();

    int getAcademicYear();

    int getSection();

    string getUsername();

    string getPassword();

    string getProgram();

    char getGender();

    // Usable Functions for creation or anything
    void register_courses(Course& registered_course);
    void print_courses_list();
    void unregister_course(string& courseName);
    bool is_registered_course(string& courseName);
    int get_course_count();
    void add_location(Location& location_to_set);
    void remove_location(string location_name);
};


#endif //DSCODE_USER_H
