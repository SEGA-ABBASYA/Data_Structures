#include "database.h"

Database::Database() {

}

void Database::read()
{


    ReadAdmin();
    ReadCourses();
}
void Database::write()
{
    WriteAdmin();
    WriteCourses();
}

void Database::WriteAdmin() {

    ofstream Writer("admin.txt");

    if (Writer.is_open()) {

        Writer << admin.getUsername() << " " << admin.getPassword();
        Writer.close();
    }

    else {
        cout << "Error opening Admin.txt for writing." << endl;
    }
}



void Database::ReadAdmin() {

    ifstream Reader("admin.txt");

    if (Reader.is_open()) {

        string username, password;
        Reader >> username >> password;

        admin.setUsername(username);
        admin.setPassword(password);

        Reader.close();

    }
    else {
        cout << "Error opening Admin.txt for reading." << endl;
    }
}

void Database::WriteCourses() {

    ofstream Writer("Courses.txt");
    Course c ("malak","1");  courses["malak"]=c;
    if (Writer.is_open()) {
        for (auto& course : courses) {

            Writer << course.second.getCourseName() << "\n";
            Writer << course.second.getDepartment() << "\n";

              Writer << course.second.getLab_String()<< "\n";
              Writer <<  course.second.getSection_String() << "\n";


            // Write doctors
            for (auto& doctor : course.second.getDoctors()) {
                Writer << doctor <<'\n';
            }

            Writer << "---\n";

            // Write TAs
            for (auto& ta : course.second.getTAs()) {
                Writer << ta << '\n';
            }

            Writer << "---\n";
        }
        Writer.close();
        \
    } else {
        cout << "Error opening Courses.txt for writing." << endl;
    }
}

void Database::ReadCourses() {

    ifstream Reader("Courses.txt");

    if (Reader.is_open()) {
        string line;

        while (getline(Reader, line)) {
            if (line == "---") {
                continue;
            }

            string courseName = line;
            string department, doctor, ta, section_string,lab_string; bool section,Lab;
            vector<string> doctors, teachingAssistants;

            getline(Reader, department);
             getline(Reader, section_string);
              getline(Reader, lab_string);

            while (getline(Reader, doctor) && doctor != "---") {
                doctors.push_back(doctor);
            }

            while (getline(Reader, ta) && ta != "---") {
                teachingAssistants.push_back(ta);
            }

            if(section_string=="yes") section=1;
            else section=0;

            if(lab_string=="yes") Lab=1;
            else Lab=0;

            Course course(courseName, department,Lab,section, doctors, teachingAssistants);
            courses[courseName]=course;
        }

    } else {
        cout << "Error opening Courses.txt for reading." << endl;
    }
}

