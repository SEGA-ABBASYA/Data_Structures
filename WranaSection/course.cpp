#include "course.h"
using namespace std;

course::course(void)
{

}

course::course(string name, string dep)
{
    courseName = name;
    department = dep;
}

course::course(string name, string dep, vector<string> drs, vector<string> TAs)
{
    courseName = name;
    department = dep;
    doctors = drs;
    teachingAssistants = TAs;
}

course::~course(void)
{
    doctors.clear();
    teachingAssistants.clear();
}

void course::setCourseName(string name)
{
    courseName = name;
}

void course::setDepartment(string dep)
{
    department = dep;
}

string course::getCourseName()
{
    return courseName;
}

string course::getDepartment()
{
    return department;
}

vector<string> course::getDoctors()
{
    return doctors;
}

vector<string> course::getTAs()
{
    return teachingAssistants;
}

void course::addDoctor(string doctor)
{
    doctors.push_back(doctor);
}

void course::removeDoctor(string doctor)
{
    doctors.erase(remove(doctors.begin(), doctors.end(), doctor), doctors.end());
}

void course::addTA(string teachingAssistant)
{
    teachingAssistants.push_back(teachingAssistant);
}

void course::removeTA(string teachingAssistant)
{
    teachingAssistants.erase(remove(teachingAssistants.begin(), teachingAssistants.end(), teachingAssistant), teachingAssistants.end());
}
