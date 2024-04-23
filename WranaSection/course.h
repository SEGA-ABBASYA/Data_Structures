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

    bool hasLab;
    bool hasSection;

    vector<string> doctors;
    vector<string> teachingAssistants;

public:
    Course(void);
    Course(string name, string dep);
    Course(string name, string dep, bool lab, bool section, vector<string> drs, vector<string> TAs);
    ~Course(void);


    void setCourseName(string);
    void setDepartment(string);

    string getCourseName();
    string getDepartment();

    void setLab(bool lab);
    void setSection(bool section);

    vector<string> getDoctors();
    vector<string> getTAs();

    void addDoctor(string);
    void removeDoctor(string);
    void addTA(string);
    void removeTA(string);
};

#endif // COURSE_H
