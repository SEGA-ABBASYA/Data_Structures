#ifndef DSCODE_USER_H
#define DSCODE_USER_H

#include "Schedule.h"
#include "course.h"
#include "location.h"
#include <iostream>
#include <unordered_map>
#include <QMap>
#include <map>
#include <set>

using namespace std;
struct userData {
    string name;
    string email;
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

public:
    //hashmaps
    set<string> registered_courses;
    unordered_map<string, bool> lecture, lab, tutorial;
    map<Timetable, Schedule> current_schedule;
    map<string,User*> friends;

    // Constructor
    User();
    User(string& name, string& email, int& id, int& academic_year, int& section, string& username, string& password, string& program, char& gender);

    // Setters
    void setName(string& name);

    void setEmail(string& email);

    void setId(int id);

    void setAcademicYear(int year);

    void setSection(int& section);

    void setUsername(string& username);

    void setPassword(string& password);

    void setProgram(string& program);

    void setGender(char gender);


    // Getters
    string getName();

    string getEmail();

    int getId();

    int getAcademicYear();

    int getSection();

    string getUsername();

    string getPassword();

    string getProgram();

    char getGender();

    // Usable Functions for creation or anything

    // course functions
    void register_courses(string courseName);
    void print_courses_list();
    void unregister_course(string courseName);
    bool is_registered_course(string courseName);
    int get_course_count();

    // schedule functions
    void add_Schedule(Schedule schedule_to_set);
    void remove_Schedule(Timetable);

    // friends functions
    void add_friend(User* friendUser);
    void remove_friend(string friendUsername);
    bool has_friend(string friendUsername);
    int get_friendsCount();
    vector<User*> get_allFriends();
    void clear_friends();
    void printMap();

};


#endif
