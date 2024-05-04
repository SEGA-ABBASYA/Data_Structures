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
    AdminView(QWidget *parent = nullptr);
    void Write_Courses_table();
    void Add_course_row();
    void Delete_course_row();

    ~AdminView();







private slots:

    void on_Test_toggled();


    void on_course_icon_toggled(bool checked);

    void on_graph_icon_toggled(bool checked);

    void on_student_icon_toggled(bool checked);

    void on_schedule_icon_toggled(bool checked);

    void on_Test_2_toggled();

    void on_FrienddsButton_toggled(bool checked);

    void on_NotificationButton_toggled(bool checked);








    void on_pushButton_18_clicked();

    void on_pushButton_clicked();





    void on_pushButton_3_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();








private:
    Ui::MainWindow *ui;
};
#endif // USER_VIEW_H