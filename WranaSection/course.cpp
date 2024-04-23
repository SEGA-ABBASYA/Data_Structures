#include "course.h"
using namespace std;

Course::Course(void)
{

}

Course::Course(string name, string dep)
{
    courseName = name;
    department = dep;
}

Course::Course(string name, string dep, vector<string> drs, vector<string> TAs)
{
    courseName = name;
    department = dep;
    doctors = drs;
    teachingAssistants = TAs;
}

Course::~Course(void)
{
    doctors.clear();
    teachingAssistants.clear();
}

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
