#include "course.h"
using namespace std;

Course::Course(void)
//Constructors
{

}

Course::Course(string name, string dep)
{
    courseName = name;
    department = dep;
    hasLab = true;
    hasSection = true;
}

Course::Course(string name, string dep, vector<string> drs, vector<string> TAs)
course::course(string name, string dep, bool lab, bool section, vector<string> drs, vector<string> TAs)
{
    courseName = name;
    department = dep;
    hasLab = lab;
    hasSection = section;
    doctors = drs;
    teachingAssistants = TAs;
}

Course::~Course(void)
// Destructor
course::~course(void)
{
    doctors.clear();
    teachingAssistants.clear();
}

void Course::setCourseName(string name)
//Setters and Getters for CourseName & Department
void course::setCourseName(string name)
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
>>>>>>> origin/course
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
