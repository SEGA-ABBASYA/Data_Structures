#ifndef USER_VIEW_H
#define USER_VIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class UserView : public QMainWindow
{
    Q_OBJECT

public:
    UserView(QWidget *parent = nullptr);
    ~UserView();


private slots:

    void on_Test_toggled();


    void on_course_icon_toggled(bool checked);

    void on_graph_icon_toggled(bool checked);

    void on_student_icon_toggled(bool checked);

    void on_schedule_icon_toggled(bool checked);

    void on_Test_2_toggled();

    void on_FrienddsButton_toggled(bool checked);

    void on_NotificationButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // USER_VIEW_H
