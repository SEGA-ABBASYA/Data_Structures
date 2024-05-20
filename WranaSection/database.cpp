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

map<string, Location> Database::locations;
map<string,Course> Database::courses;
map<Timetable, vector<Schedule>> Database::schedules;
QMap<string, User> Database::users;
Admin Database::admin;

vector<string>Database::UnderGroundFloor;
vector<string>Database::GroundFloor;
vector<string>Database::FirstGeneralFloor;
vector<string>Database::FirstCreditFloor;
vector<string>Database::SecondFloor;
vector<string>Database::SecondOtherFloor;
vector<string>Database::ThirdFloor;



Database::Database() {
    adminFile.setFileName( "Files/Admin.txt");
    CoursesFile.setFileName("Files/Courses.txt");
    usersFile.setFileName("Files/Users.txt");
    friendsFile.setFileName("Files/Friends.txt");
    chatFile.setFileName("Files/Chat.txt");
    locationsFile.setFileName("Files/Locations.txt");
    schedulesFile.setFileName("Files/Schedules.txt");
    UnderGroundFile.setFileName("Files/UnderGroundfloor.txt");
    GroundFile.setFileName("Files/Groundfloor.txt");
    FirstGeneralFile.setFileName("Files/FirstGeneralfloor.txt");
    FirstCreditFile.setFileName("Files/FirstCreditfloor.txt");
    SecondFile.setFileName("Files/Secondfloor.txt");
    SecondOtherFile.setFileName("Files/SecondOtherfloor.txt");
    ThirdFile.setFileName("Files/Thirdfloor.txt");
}

void Database::read()
{
    ReadAdmin();
    ReadCourses();
    readLocations();
    readSchedule();
    readUsers();
    readFriends();
    readChat();
    Read_UnderGroundFloor();
    Read_GroundFloor();
    Read_FirstGeneralFloor();
    Read_FirstCreditFloor();
    Read_SecondFloor();
    Read_SecondOtherFloor();
    Read_ThirdFloor();
}

void Database::write()
{
    WriteAdmin();
    WriteCourses();
    writeLocations();
    writeSchedule();
    writeUsers();
    writeFriends();
    writeChat();
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
                string courseName = userData[i].toStdString();
                newUser.register_courses(courseName);
                newUser.lecture[courseName] = userData[++i].toInt();
                newUser.lab[courseName] = userData[++i].toInt();
                newUser.tutorial[courseName] = userData[++i].toInt();
                qDebug() << userData[i] << '\n';
            }
            ////////////add schedule
            while(userData[++i] != "0"){
                string sch_name = userData[i].toStdString();
                Timetable date = {userData[++i].toInt(), userData[++i].toInt(), userData[++i].toStdString()};
                qDebug() << sch_name << ' ' << date.day << '\n';
                for(auto& sch : schedules[date]){
                    if(sch.getName() == sch_name){
                        newUser.add_Schedule(sch);
                        break;
                    }
                }
            }
            ////////////add notifications
            while(userData[++i] != "0"){
                QString noti = userData[i];
                newUser.addNotification(noti);
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

void Database::readFriends()
{
    if (friendsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&friendsFile);
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList userData = line.split(',');
            int i = 0;
            User *user = &users[userData[i].toStdString()];
            ////////////add friends
            while(userData[++i] != "0"){
                string friendName = userData[i].toStdString();
                user->add_friend(&users[friendName]);
            }
        }
        friendsFile.close();
        qDebug() << "friendsFile read successfully.";
    } else {
        qDebug() << "Failed to open the friendsFile for reading.";
    }
}

void Database::readChat()
{
    if (chatFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&chatFile);
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList userData = line.split(',');
            int i = 0;
            User *fromUser = &users[userData[i].toStdString()];
            string toUser = userData[++i].toStdString();
            ////////////add messages
            while(userData[++i] != "0"){
                QString msg = userData[i];
                fromUser->addMessage(toUser, msg);
            }
        }
        chatFile.close();
        qDebug() << "chatFile read successfully.";
    } else {
        qDebug() << "Failed to open the chatFile for reading.";
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
            locations[name] = newLoc;
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
                content.append(split + course);
                content.append(split + QString::number(user.lecture[course]));
                content.append(split + QString::number(user.lab[course]));
                content.append(split + QString::number(user.tutorial[course]));
            }
            //courses_finished
            content.append(",0");

            //////////read schedule
            for(auto& sch : user.current_schedule){
                Timetable date = sch.second.getDate();
                content.append(split + sch.second.getName());
                content.append(split + QString::number(date.hour));
                content.append(split + QString::number(date.minutes));
                content.append(split + date.day);
            }
            //schedule_finished
            content.append(",0");

            //////////read notifications
            for(auto& noti : user.notifications){
                content.append(split + noti);
            }
            //notifications_finished
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

void Database::writeFriends()
{
    if (friendsFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&friendsFile);
        char split = ',';
        QString content;
        for(auto& user : users){
            content.clear();
            content.append(user.getUsername());

            for(auto& frien : user.friends){
                content.append(split + frien.first);
            }
            //friends_finished
            content.append(",0");

            //push_to_the_file
            stream << content << '\n';
        }
        friendsFile.close();
        qDebug() << "friendsFile written successfully.";
    } else {
        qDebug() << "Failed to open the friendsFile for writing.";
    }
}

void Database::writeChat()
{
    if (chatFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&chatFile);
        char split = ',';
        QString content;
        for(auto& user : users){
            for(auto& chat : user.chatHistory){
                content.clear();
                content.append(user.getUsername() + split + chat.first);
                for(auto msg : chat.second){
                    content.append(split + msg);
                }
                //msgs_finished
                content.append(",0");
                //push_to_the_file
                stream << content << '\n';
            }
        }
        chatFile.close();
        qDebug() << "chatFile written successfully.";
    } else {
        qDebug() << "Failed to open the chatFile for writing.";
    }
}

void Database::writeLocations()
{
    if (locationsFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&locationsFile);
        char split = ',';
        QString content;
        for(auto& loc : locations){
            content.clear();

            content.append(QString::number(loc.second.getFloor()) + split);
            content.append(QString::number(loc.second.getHall()) + split);
            content.append(loc.second.getName() + split);
            content.append(QString::number(loc.second.getNode().first) + split);
            content.append(QString::number(loc.second.getNode().second));

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
            string type = schData[++i].toStdString();
            int section = schData[++i].toInt();
            bool group = schData[++i].toInt();
            Timetable date = {schData[++i].toInt(), schData[++i].toInt(), schData[++i].toStdString()};
            string course = schData[++i].toStdString();

            Schedule newSch(name, type, section, group, date, course);
            qDebug() << newSch.getName() << ' ' << newSch.getGroup() << '\n';
            //insert in map
            schedules[date].push_back(newSch);
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
        for(auto& vec : schedules) for(auto& sch : vec.second){
                content.clear();

                content.append(sch.getName() + split);
                content.append(sch.getType() + split);
                content.append(QString::number(sch.getSection()) + split);
                content.append(QString::number(sch.getGroup()) + split);
                content.append(QString::number(sch.getDate().hour) + split);
                content.append(QString::number(sch.getDate().minutes) + split);
                content.append(sch.getDate().day + split);
                content.append(sch.getCourse() + split);

                //push_to_the_file
                stream << content << '\n';
            }
        schedulesFile.close();
        qDebug() << "schedulesFile written successfully.";
    } else {
        qDebug() << "Failed to open the schedulesFile for writing.";
    }
}
void Database::Read_UnderGroundFloor()
{
    ifstream Reader(UnderGroundFile.fileName().toStdString());

    if (Reader.is_open()) {
        string line;

        while (getline(Reader, line)) {

            UnderGroundFloor.push_back(line);
        }
         cout << "UnderGroundFile read successfully"<< endl;
    }
      else
    cout << "Error opening UnderGround.txt for reading." << endl;

}
void Database::Read_GroundFloor()
{
    ifstream Reader(GroundFile.fileName().toStdString());

    if (Reader.is_open()) {
        string line;

        while (getline(Reader, line)) {

            GroundFloor.push_back(line);
        }
        cout << "GroundFile read successfully"<< endl;
    }
    else
        cout << "Error opening Ground.txt for reading." << endl;
}
void Database::Read_FirstGeneralFloor()
{
    ifstream Reader(FirstGeneralFile.fileName().toStdString());

    if (Reader.is_open()) {
        string line;

        while (getline(Reader, line)) {

            FirstGeneralFloor.push_back(line);
        }
        cout << "FirstGeneralFile read successfully"<< endl;
    }
    else
        cout << "Error opening FirstGeneral.txt for reading." << endl;
}
void Database::Read_FirstCreditFloor()
{



    ifstream Reader(FirstCreditFile.fileName().toStdString());

    if (Reader.is_open()) {
        string line;

        while (getline(Reader, line)) {

            FirstCreditFloor.push_back(line);
           // cout<<line<<'\n';

        }


    }
    else
        cout << "Error opening FirstCredit.txt for reading." << endl;
}
void Database::Read_SecondFloor()
{
    ifstream Reader(SecondFile.fileName().toStdString());

    if (Reader.is_open()) {
        string line;

        while (getline(Reader, line)) {

           SecondFloor.push_back(line);
        }
        cout << "SecondFile read successfully"<< endl;
    }
    else
        cout << "Error opening Second.txt for reading." << endl;
}
void Database::Read_SecondOtherFloor()
{
    ifstream Reader(SecondOtherFile.fileName().toStdString());

    if (Reader.is_open()) {
        string line;

        while (getline(Reader, line)) {

            SecondOtherFloor.push_back(line);
        }
        cout << "SecondOtherFile read successfully"<< endl;
    }
    else
        cout << "Error opening SecondOther.txt for reading." << endl;
}
void Database::Read_ThirdFloor()
{
    ifstream Reader(ThirdFile.fileName().toStdString());

    if (Reader.is_open()) {
        string line;

        while (getline(Reader, line)) {

            ThirdFloor.push_back(line);
        }
        cout << "ThirdFile read successfully"<< endl;
    }
    else
        cout << "Error opening Third.txt for reading." << endl;
}
