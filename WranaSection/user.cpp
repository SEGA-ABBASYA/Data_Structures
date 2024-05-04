#include "user.h"
#include "course.h"
#include "Schedule.h"
#include <map>
#include<vector>

using namespace std;
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
void User::register_courses(Course registered_course) {
    registered_courses[registered_course.getCourseName()] = registered_course;
}

void User::unregister_course(string courseName) {
    registered_courses.erase(courseName);
}

bool User::is_registered_course(string courseName) {
    return registered_courses.find(courseName) != registered_courses.end();
}
int User::get_course_count() {
    int numberOftheCourses = registered_courses.size();
    return numberOftheCourses;
}

void User::print_courses_list() {
    int i = 1;
    for (auto& it : registered_courses) {
        int j = 1;
        int z = 1;
        cout << "Course Name " << i << ":" << " " << it.second.getCourseName() << endl;
        cout << "Course Department " << i << ":" << " " << it.second.getDepartment() << endl;
        vector<string> doctors = it.second.getDoctors();
        vector<string> teachingAssistants = it.second.getTAs();
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
    current_schedule.remove(schedule_timetable);
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
    return friends.size();
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
