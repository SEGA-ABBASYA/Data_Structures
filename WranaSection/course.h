#ifndef COURSE_H
#define COURSE_H

#include<string>
#include<vector>
#include <iostream>
using namespace std;

class Course
{
    string courseName;
    string department;
    vector<string> doctors;
    vector<string> teachingAssistants;

public:
    Course(void);
    Course(string name, string dep);
    Course(string name, string dep, vector<string> drs, vector<string> TAs);
    ~Course(void);

    void setCourseName(string);
    void setDepartment(string);

    string getCourseName();
    string getDepartment();
    vector<string> getDoctors();
    vector<string> getTAs();

    void addDoctor(string);
    void removeDoctor(string);
    void addTA(string);
    void removeTA(string);
};

#endif // COURSE_H
