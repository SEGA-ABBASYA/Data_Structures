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

    ofstream Writer("Admin.txt");

    if (Writer.is_open()) {

        Writer << admin.getUsername() << " " << admin.getPassword();
        Writer.close();
    }

    else {
        cout << "Error opening Admin.txt for writing." << endl;
    }
}



void Database::ReadAdmin() {

    ifstream Reader("Admin.txt");

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

    if (Writer.is_open()) {
        for (auto& course : courses) {
            Writer << course.getCourseName() << "\n";
            Writer << course.getDepartment() << "\n";

              Writer << course.getLab_S()<< "\n";
                Writer <<  course.getSection_S() << "\n";


            // Write doctors
            for (auto& doctor : course.getDoctors()) {
                Writer << doctor <<'\n';
            }

            Writer << "---\n";

            // Write TAs
            for (auto& ta : course.getTAs()) {
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
            string department, doctor, ta, section,lab; int sec,Lab;
            vector<string> doctors, teachingAssistants;

            getline(Reader, department);
             getline(Reader, section);
              getline(Reader, lab);

            while (getline(Reader, doctor) && doctor != "---") {
                doctors.push_back(doctor);
            }

            while (getline(Reader, ta) && ta != "---") {
                teachingAssistants.push_back(ta);
            }

            if(section=="yes") sec=1;
            else sec=0;

            if(lab=="yes") Lab=1;
            else Lab=0;

            Course course(courseName, department,Lab,sec, doctors, teachingAssistants);
            courses.push_back(course);
        }

    } else {
        cout << "Error opening Courses.txt for reading." << endl;
    }
}

