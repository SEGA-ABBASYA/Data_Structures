#ifndef USER_VIEW_H
#define USER_VIEW_H

#include <QWidget>

namespace Ui {
class UserView;
}

class UserView : public QWidget
{
    Q_OBJECT

public:
    explicit UserView(QWidget *parent = nullptr);
    ~UserView();

private slots:
    void on_Swapfull_toggled();

    void on_Swapicons_toggled();

    void on_courseicons_toggled(bool checked);

    void on_graphicons_toggled(bool checked);

    void on_studenticons_toggled(bool checked);


    void on_scheduleicons_toggled(bool checked);

    void on_friendicons_toggled(bool checked);

    void on_notificationicons_toggled(bool checked);

private:
    Ui::UserView *ui;
};

#endif // USER_VIEW_H
