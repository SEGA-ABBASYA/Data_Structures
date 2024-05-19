#include "scheduleadddelete.h"
#include "ui_scheduleadddelete.h"
#include "database.h"
#include <QMessageBox>

ScheduleAddDelete::ScheduleAddDelete(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScheduleAddDelete)
{
    ui->setupUi(this);
    Timetable tt = Database::CurrentUserTT;
    for (auto itr : Database::schedules[tt])
    {
        string coursename = itr.getCourse();
        string groupstring,sectionstring = to_string(itr.getSection());
        if (itr.getGroup())
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

