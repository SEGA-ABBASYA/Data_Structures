#include "scheduleadddelete.h"
#include "ui_scheduleadddelete.h"

ScheduleAddDelete::ScheduleAddDelete(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScheduleAddDelete)
{
    ui->setupUi(this);
}

ScheduleAddDelete::~ScheduleAddDelete()
{
    delete ui;
}
