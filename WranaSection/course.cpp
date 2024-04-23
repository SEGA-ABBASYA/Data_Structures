#include "course.h"
using namespace std;


//Constructors
Course::Course(void)
{

}

Course::Course(string name, string dep)
{
    courseName = name;
    department = dep;
    hasLab = true;
    hasSection = true;
}


Course::Course(string name, string dep, bool lab, bool section, vector<string> drs, vector<string> TAs)
{
    courseName = name;
    department = dep;
    hasLab = lab;
    hasSection = section;
    doctors = drs;
    teachingAssistants = TAs;
}

// Destructor
Course::~Course(void)
{
    doctors.clear();
    teachingAssistants.clear();
}

//Setters and Getters for CourseName & Department
void Course::setCourseName(string name)
{
    courseName = name;
}

void Course::setDepartment(string dep)
{
    department = dep;
}

string Course::getCourseName()
{
    return courseName;
}

string Course::getDepartment()
{
    return department;
}


//Setters and Getters for hasLab & hasSection
void Course::setLab(bool lab)
{
    hasLab = lab;
}
void Course::setSection(bool section)
{
    hasSection = section;
}


//Methods for Doctors & TAs
vector<string> Course::getDoctors()
{
    return doctors;
}

vector<string> Course::getTAs()
{
    return teachingAssistants;
}

void Course::addDoctor(string doctor)
{
    doctors.push_back(doctor);
}

void Course::removeDoctor(string doctor)
{
    doctors.erase(remove(doctors.begin(), doctors.end(), doctor), doctors.end());
}

void Course::addTA(string teachingAssistant)
{
    teachingAssistants.push_back(teachingAssistant);
}

void Course::removeTA(string teachingAssistant)
{
    teachingAssistants.erase(remove(teachingAssistants.begin(), teachingAssistants.end(), teachingAssistant), teachingAssistants.end());
}
