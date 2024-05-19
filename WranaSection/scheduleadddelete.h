#ifndef SCHEDULEADDDELETE_H
#define SCHEDULEADDDELETE_H

#include <QDialog>

namespace Ui {
class ScheduleAddDelete;
}

class ScheduleAddDelete : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleAddDelete(QWidget *parent = nullptr);
    ~ScheduleAddDelete();

private slots:
    void on_AddButton_clicked();

private:
    Ui::ScheduleAddDelete *ui;
};

#endif // SCHEDULEADDDELETE_H
