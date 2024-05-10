#include "database.h"
#include "user.h"
#include "Schedule.h"
#include"course.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QMap>

QMap<QString, Location> Database::locations;
map<string,Course> Database::courses;
QMap<string, QMap<Timetable, Schedule>> Database::schedules;
QMap<string, User> Database::users;
Admin Database::admin;




Database::Database() {
    adminFile.setFileName("Files/Admin.txt");
    CoursesFile.setFileName("Files/Courses.txt");
    usersFile.setFileName("Files/Users.txt");
    locationsFile.setFileName("Files/Locations.txt");
    schedulesFile.setFileName("Files/Schedules.txt");
}

void Database::read()
{
    ReadAdmin();
    ReadCourses();
    readLocations();
    readSchedule();
    readUsers();
}

void Database::write()
{
    WriteAdmin();
    WriteCourses();
    writeLocations();
    writeSchedule();
    writeUsers();
}

void Database::WriteAdmin() {

    ofstream Writer(adminFile.fileName().toStdString());

    if (Writer.is_open()) {

        Writer << admin.getUsername() << " " << admin.getPassword();
        Writer.close();
    }

    else {
        cout << "Error opening Admin.txt for writing." << endl;
    }
}



void Database::ReadAdmin() {

    ifstream Reader(adminFile.fileName().toStdString());

    if (Reader.is_open()) {

        string username, password;
        Reader >> username >> password;
        qDebug() << username << ' ' << password << '\n';
        admin.setUsername(username);
        admin.setPassword(password);

        Reader.close();

    }
    else {
        cout << "Error opening Admin.txt for reading." << endl;
    }
}

void Database::WriteCourses() {


    ofstream Writer(CoursesFile.fileName().toStdString());
    if (Writer.is_open()) {
        for (auto& course : courses) {

            Writer << course.second.getCourseName() << "\n";
            Writer << course.second.getDepartment() << "\n";
            Writer << course.second.getLab_S()<< "\n";
            Writer <<  course.second.getSection_S() << "\n";

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
        cout << "CoursesFile Written Successfully" <<endl;
    } else {
        cout << "Error opening Courses.txt for writing." << endl;
    }
}

void Database::ReadCourses() {

    ifstream Reader(CoursesFile.fileName().toStdString());

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
            getline(Reader, lab_string);
             getline(Reader, section_string);

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
          //  if(courseName=="") continue;
            Course course(courseName, department,Lab,section, doctors, teachingAssistants);
            qDebug() << courseName << ' ' << department << '\n';
            courses[courseName]=course;
        }
        cout << "CoursesFile read successfully"<< endl;
    } else {
        cout << "Error opening Courses.txt for reading." << endl;
    }
}

void Database::readUsers()
{
    if (usersFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&usersFile);
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList userData = line.split(',');
            int i = 0;
            string name = userData[i].toStdString();
            string email = userData[++i].toStdString();
            int id = userData[++i].toInt();
            int academic_year = userData[++i].toInt();
            int section = userData[++i].toInt();
            string user_name = userData[++i].toStdString();
            string password  = userData[++i].toStdString();
            string program = userData[++i].toStdString();
            char gender = userData[++i].toStdString()[0];
            User newUser(name, email, id, academic_year, section, user_name, password, program, gender);
            qDebug() << newUser.getName() << ' ' << newUser.getPassword() << '\n';
            ////////////add courses
            while(userData[++i] != "0"){
                newUser.register_courses(courses[userData[i].toStdString()]);
                qDebug() << userData[i] << '\n';
            }
            ////////////add schedule
            while(userData[++i] != "0"){
                string sch_name = userData[i].toStdString();
                Timetable date = {userData[++i].toInt(), userData[++i].toInt(), userData[++i].toStdString()};
                qDebug() << sch_name << ' ' << date.day << '\n';
                newUser.add_Schedule(schedules[sch_name][date]);
            }
            /////insert into map
            users.insert(user_name, newUser);
        }
        usersFile.close();
        qDebug() << "userFile read successfully.";
    } else {
        qDebug() << "Failed to open the userFile for reading.";
    }
}

void Database::readLocations()
{
    if (locationsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&locationsFile);
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList locData = line.split(',');
            int i = 0;
            int floor = locData[i].toInt();
            bool hall = locData[++i].toInt();
            string name = locData[++i].toStdString();
            pair<int, int> node = {locData[++i].toInt(), locData[++i].toInt()};
            Location newLoc(floor, hall, name, node);
            qDebug() << newLoc.getName() << ' ' << newLoc.getNode().first << ' '<< newLoc.getNode().second << '\n';
            locations[QString::fromStdString(name)] = newLoc;
        }
        locationsFile.close();
        qDebug() << "LocationsFile read successfully.";
    } else {
        qDebug() << "Failed to open the locationsFile for reading.";
    }
}

void Database::writeUsers()
{
    if (usersFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&usersFile);
        char split = ',';
        QString content;
        for(auto& user : users){
            content.clear();

            content.append(user.getName() + split);
            content.append(user.getEmail() + split);
            content.append(QString::number(user.getId()) + split);
            content.append(QString::number(user.getAcademicYear()) + split);
            content.append(QString::number(user.getSection()) + split);
            content.append(user.getUsername() + split);
            content.append(user.getPassword() + split);
            content.append(user.getProgram() + split);
            content.append(user.getGender());

            //////////read courses
            for(auto& course : user.registered_courses){
                content.append(split + course.first);
            }
            //courses_finished
            content.append(",0");

            //////////read schedule
            for(auto& sch : user.current_schedule.values()){
                Timetable date = sch.getDate();
                content.append(split + sch.getName());
                content.append(split + QString::number(date.hour));
                content.append(split + QString::number(date.minutes));
                content.append(split + date.day);
            }
            //schedule_finished
            content.append(",0");

            //push_to_the_file
            stream << content << '\n';
        }
        usersFile.close();
        qDebug() << "userFile written successfully.";
    } else {
        qDebug() << "Failed to open the userFile for writing.";
    }
}

void Database::writeLocations()
{
    if (locationsFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&locationsFile);
        char split = ',';
        QString content;
        for(auto& loc : locations.values()){
            content.clear();

            content.append(QString::number(loc.getFloor()) + split);
            content.append(QString::number(loc.getHall()) + split);
            content.append(loc.getName() + split);
            content.append(QString::number(loc.getNode().first) + split);
            content.append(QString::number(loc.getNode().second));

            //push_to_the_file
            stream << content << '\n';
        }
        locationsFile.close();
        qDebug() << "locationsFile written successfully.";
    } else {
        qDebug() << "Failed to open the locationsFile for writing.";
    }
}

void Database::readSchedule()
{
    if (schedulesFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&schedulesFile);
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList schData = line.split(',');
            int i = 0;
            string name  = schData[i].toStdString();
            ////////////add doctors
            queue<string> doctors;
            while(schData[++i] != "0"){
                doctors.push(schData[i].toStdString());
                qDebug() << doctors.front() << '\n';
            }
            bool midterm = schData[++i].toInt();
            string type = schData[++i].toStdString();
            int section = schData[++i].toInt();
            bool group = schData[++i].toInt();
            Timetable date = {schData[++i].toInt(), schData[++i].toInt(), schData[++i].toStdString()};
            Course course = courses[schData[++i].toStdString()];
            string dep = schData[++i].toStdString();

            Schedule newSch(name, doctors, midterm, type, section, group, date, course, dep);
            qDebug() << newSch.getName() << ' ' << newSch.getGroup() << '\n';
            //insert in map
            schedules[name][date] = newSch;
        }
        schedulesFile.close();
        qDebug() << "schedulesFile read successfully.";
    } else {
        qDebug() << "Failed to open the schedulesFile for reading.";
    }
}

void Database::writeSchedule()
{
    if (schedulesFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&schedulesFile);
        char split = ',';
        QString content;
        for(auto& map : schedules.values()) for(auto& sch : map.values()){
                content.clear();

                content.append(sch.getName() + split);
                ////////////add doctors
                queue<string> doctors = sch.getDoctor();
                while(!doctors.empty()){
                    content.append(doctors.front() + split);
                    doctors.pop();
                }
                content.append( "0,");

                content.append(QString::number(sch.getMidterm()) + split);
                content.append(sch.getType() + split);
                content.append(QString::number(sch.getSection()) + split);
                content.append(QString::number(sch.getGroup()) + split);
                content.append(QString::number(sch.getDate().hour) + split);
                content.append(QString::number(sch.getDate().minutes) + split);
                content.append(sch.getDate().day + split);
                content.append(sch.getCourse().getCourseName() + split);
                content.append(sch.getDepartment());

                //push_to_the_file
                stream << content << '\n';
            }
        schedulesFile.close();
        qDebug() << "schedulesFile written successfully.";
    } else {
        qDebug() << "Failed to open the schedulesFile for writing.";
    }
}

