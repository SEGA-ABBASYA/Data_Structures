#include "scheduleadddelete.h"
#include "ui_scheduleadddelete.h"
#include "database.h"
#include <QMessageBox>

QListWidgetItem *currentItem;

ScheduleAddDelete::ScheduleAddDelete(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScheduleAddDelete)
{
    ui->setupUi(this);
    Timetable tt = Database::CurrentUserTT;
    currentItem = ui->CoursesList->currentItem();
    for (auto itr : Database::schedules[tt])
    {
        string coursename = itr.getCourse();
        string groupstring,sectionstring = to_string(itr.getSection());
        if (itr.getGroup()==0)
            groupstring = "G1";
        else
            groupstring = "G2";
        ui->CoursesList->addItem(QString::fromStdString("Name : " + coursename + ",Type : " + itr.getType() + ",Location : " + itr.getName() + ",Section : " + sectionstring + ",Group : " + groupstring));
    }
}

ScheduleAddDelete::~ScheduleAddDelete()
{
    delete ui;
}

void ScheduleAddDelete::on_AddButton_clicked()
{
    string courseName = ui->CourseTextField->text().toStdString(),locationName = ui->LocationTextField->text().toStdString();
    string typeName = ui->TypeTextField->text().toStdString();
    int sectionNum = ui->SectionTextField->text().toInt();
    if (!Database::courses.count(courseName))
    {
        QMessageBox::warning(this,"Invalid Course","Please enter a valid course!");
        return;
    }
    if (!Database::locations.count(locationName))
    {
        QMessageBox::warning(this,"Invalid Location","Please enter a valid location!");
        return;
    }
    if ((typeName != "Lab" && typeName != "Lecture" && typeName != "Tutorial") || ((typeName == "Lab" && !Database::courses[courseName].getLab()) || (typeName == "Tutorial" && !Database::courses[courseName].getSection())))
    {
        QMessageBox::warning(this,"Invalid Type","Please enter a valid type!");
        return;
    }
    if (sectionNum < 1 || sectionNum > 30)
    {
        QMessageBox::warning(this,"Invalid Section","Please enter a valid section!");
        return;
    }
    if (!(ui->G1radiobutton->isChecked() || ui->G2radiobutton->isChecked()))
    {
        QMessageBox::warning(this,"Invalid Group","Please select a group section!");
        return;
    }

    Schedule newSchedule(locationName,typeName,sectionNum,0,Database::CurrentUserTT,courseName);
    string groupstring = "G1";
    if (ui->G2radiobutton->isChecked())
    {
        newSchedule.setGroup(1);
        groupstring = "G2";
    }

    ui->CoursesList->addItem(QString::fromStdString("Name : " + courseName + ",Type : " + typeName + ",Location : " + locationName + ",Section : " + to_string(sectionNum) + ",Group : " + groupstring));

    Database::schedules[Database::CurrentUserTT].push_back(newSchedule);
}


void ScheduleAddDelete::on_DeleteButton_clicked()
{
    if (!currentItem || currentItem->text().toStdString() == "None")
    {
        QMessageBox::warning(this,"Invalid Removal","Please select a valid schedule to remove!");
        return;
    }

    string currentstring = currentItem->text().toStdString();
    string locationName = "",CourseName = "",TypeName = "",SectionString = "";
    string currtype = Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT].getType();
    string currcourse = Database::users[Database::CurrentUser].current_schedule[Database::CurrentUserTT].getCourse();
    bool isLocationName = false,isTypeName = false,isSectionName = false;
    int groupNum,sectionNum;
    for (int i = 7;i < currentstring.size();i++)
    {
        if (currentstring[i] != ',')
        {
            if (isSectionName)
                SectionString += currentstring[i];
            else if (isLocationName)
                locationName += currentstring[i];
            else if (isTypeName)
                TypeName += currentstring[i];
            else
                CourseName += currentstring[i];
        }
        else
        {
            if (isSectionName)
                break;
            if (!isLocationName && !isTypeName)
            {
                i+=7;
                isTypeName = true;
                continue;
            }
            else if (!isLocationName)
            {
                i+=11;
                isLocationName = true;
                continue;
            }
            i+=10;
            isSectionName = true;
        }
    }
    groupNum = currentstring[currentstring.size()-1] - '0';
    groupNum--;
    sectionNum = stoi(SectionString);
    Schedule scheduleToDelete(locationName,TypeName,sectionNum,groupNum,Database::CurrentUserTT,CourseName);

    auto &schedules = Database::schedules[Database::CurrentUserTT];
    auto it = std::find(schedules.begin(), schedules.end(), scheduleToDelete);
    if (it != schedules.end())
    {
        schedules.erase(it);
    }

    for (auto &i : Database::users)
    {
        Schedule temp = i.current_schedule[Database::CurrentUserTT];
        cout << temp.getName() << ' ' << temp.getCourse() << ' ' << temp.getDate().day << ' ' << temp.getDate().hour << ' ' << temp.getType() << ' ' << temp.getSection() << ' ' << temp.getGroup() << endl;
        cout << scheduleToDelete.getName() << ' ' << scheduleToDelete.getCourse() << ' ' << scheduleToDelete.getDate().day << ' ' << scheduleToDelete.getDate().hour << ' ' << scheduleToDelete.getType() << ' ' << scheduleToDelete.getSection() << ' ' << scheduleToDelete.getGroup() << endl;
        if (temp == scheduleToDelete)
        {
            cout << "Found" << endl;
            Schedule NoneSch("None","None",1,0,Database::CurrentUserTT,"None");
            i.current_schedule[Database::CurrentUserTT] = NoneSch;
            if (TypeName == "Lab")
            {
                cout << "Actually Deleted" << endl;
                i.lab[CourseName] = false;
            }
            else if (TypeName == "Lecture")
            {
                cout << "Actually Deleted" << endl;
                i.lecture[CourseName] = false;
            }
            else
            {
                cout << "Actually Deleted" << endl;
                i.tutorial[CourseName] = false;
            }
        }
    }

    ui->CoursesList->clear();
    ui->CoursesList->addItem(QString::fromStdString("None"));
    for (auto itr : Database::schedules[Database::CurrentUserTT])
    {
        string coursename = itr.getCourse();
        string groupstring,sectionstring = to_string(itr.getSection());
        if (itr.getGroup()==0)
            groupstring = "G1";
        else
            groupstring = "G2";
        ui->CoursesList->addItem(QString::fromStdString("Name : " + coursename + ",Type : " + itr.getType() + ",Location : " + itr.getName() + ",Section : " + sectionstring + ",Group : " + groupstring));
    }
}


void ScheduleAddDelete::on_CoursesList_itemPressed(QListWidgetItem *item)
{
    currentItem = item;
}

