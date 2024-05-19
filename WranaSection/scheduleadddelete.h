#ifndef SCHEDULEADDDELETE_H
#define SCHEDULEADDDELETE_H

#include <QDialog>
#include <QListWidgetItem>

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

    void on_DeleteButton_clicked();

    void on_CoursesList_itemPressed(QListWidgetItem *item);

private:
    Ui::ScheduleAddDelete *ui;
};

#endif // SCHEDULEADDDELETE_H
