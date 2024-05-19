#include "user.h"
#include "course.h"
#include "Schedule.h"
#include"database.h"
#include <map>
#include<vector>

using namespace std;
User::User()
{

}

User::User(string& name, string& email, int& id, int& academic_year, int& section, string& username, string& password, string& program, char& gender)
    :data{ name, email, id, academic_year, section, username, password, program, gender } {}

// Setters
void User::setName(string& name) {
    data.name = name;
}

void User::setEmail(string& email) {
    data.email = email;
}

void User::setId(int id) {
    data.id = id;
}

void User::setAcademicYear(int year) {
    data.academic_year = year;
}

void User::setSection(int& section) {
    data.section = section;
}

void User::setUsername(string& username) {
    data.user_name = username;
}

void User::setPassword(string& password) {
    data.password = password;
}

void User::setProgram(string& program) {
    data.program = program;
}

void User::setGender(char gender) {
    data.gender = gender;
}

// Getters
string User::getName() {
    return data.name;
}

string User::getEmail() {
    return data.email;
}

int User::getId() {
    return data.id;
}

int User::getAcademicYear() {
    return data.academic_year;
}

int User::getSection() {
    return data.section;
}

string User::getUsername() {
    return data.user_name;
}

string User::getPassword() {
    return data.password;
}

string User::getProgram() {
    return data.program;
}

char User::getGender() {
    return data.gender;
}

// course functions
void User::register_courses(string courseName) {
    registered_courses.insert(courseName);
}

void User::unregister_course(string courseName) {
    registered_courses.erase(courseName);
}

bool User::is_registered_course(string courseName) {
    return registered_courses.find(courseName) != registered_courses.end();
}
int User::get_course_count() {
    return int(registered_courses.size());
}

void User::print_courses_list() {
    int i = 1;
    for(auto course : registered_courses){
        auto it = Database::courses[course];
        int j = 1;
        int z = 1;
        cout << "Course Name " << i << ":" << " " << it.getCourseName() << endl;
        cout << "Course Department " << i << ":" << " " << it.getDepartment() << endl;
        vector<string> doctors = it.getDoctors();
        vector<string> teachingAssistants = it.getTAs();
        for (auto& doctor : doctors) {
            cout << "Course Doctor " << j << ":" << doctor << endl;
            j++;
        }
        for (auto& TA : teachingAssistants) {
            cout << "Course Doctor TA " << z << ":" << TA << endl;
            z++;
        }
        i++;
    }
}

// schedule functions
void User::add_Schedule(Schedule schedule_to_set) {
    current_schedule[schedule_to_set.getDate()] = schedule_to_set;
}

void User::remove_Schedule(Timetable schedule_timetable) {
    current_schedule.erase(schedule_timetable);
}

// friends functions
void User:: add_friend(User* friendUser) {
    if (friends.find(friendUser->data.user_name) == friends.end()) {
        friends[friendUser->data.user_name] = friendUser;
        cout<<"ADD"<<endl;
    }
}

void User:: remove_friend(string friendUsername) {
    auto it = friends.find(friendUsername);
    if (it != friends.end()) {
        friends.erase(it);
        cout<<"DELETE"<<endl;
    }
}

bool User:: has_friend(string friendUsername) {
    return friends.find(friendUsername) != friends.end();
}

int User:: get_friendsCount() {
    return int(friends.size());
}

vector<User*> User:: get_allFriends() {
    vector<User*> allFriends;
    for (auto& pair : friends) {
        allFriends.push_back(pair.second);
    }
    return allFriends;
}

void User:: clear_friends() {
    friends.clear();
}

void User::printMap(){
    for(auto& i : friends){
        cout<<i.first<<endl;
    }
}

void User::addMessage(string friendName,QString message){
    chatHistory[friendName].append(message);
}

QStringList User::getChatHistory(string friendName){
    return chatHistory[friendName];
}

void User::addNotification(QString notification) {
    notifications.append(notification);
}

QStringList User::getNotifications(){
    return notifications;
}

void User::clearNotifications() {
    notifications.clear();
}

void User::updateDetails(const string& name, const string& email, int id, int academic_year, int section, const string& username, const string& password, const string& program, char gender) {
    data.name = name;
    data.email = email;
    data.id = id;
    data.academic_year = academic_year;
    data.section = section;
    data.user_name = username;
    data.password = password;
    data.program = program;
    data.gender = gender;
}



