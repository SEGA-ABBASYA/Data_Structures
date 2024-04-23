#include "course.h"
using namespace std;

//Constructors
course::course(void)
{

}

course::course(string name, string dep)
{
    courseName = name;
    department = dep;
    hasLab = true;
    hasSection = true;
}

course::course(string name, string dep, bool lab, bool section, vector<string> drs, vector<string> TAs)
{
    courseName = name;
    department = dep;
    hasLab = lab;
    hasSection = section;
    doctors = drs;
    teachingAssistants = TAs;
}

// Destructor
course::~course(void)
{
    doctors.clear();
    teachingAssistants.clear();
}

//Setters and Getters for CourseName & Department
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


//Setters and Getters for hasLab & hasSection
void course::setLab(bool lab)
{
    hasLab = lab;
}
void course::setSection(bool section)
{
    hasSection = section;
}


//Methods for Doctors & TAs
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
