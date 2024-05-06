#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class AdminView : public QMainWindow
{
    Q_OBJECT

public:
    AdminView(QWidget *parent = nullptr);
    void Write_Courses_table_edit();
     void Write_Courses_table_delete();
    void Write_Students_table_edit();
    void Write_Students_table_delete();


    ~AdminView();


private slots:

    void on_Test_toggled();


    void on_course_icon_toggled(bool checked);

    void on_graph_icon_toggled(bool checked);

    void on_student_icon_toggled(bool checked);

    void on_schedule_icon_toggled(bool checked);

    void on_Test_2_toggled();



    void on_pushButton_17_toggled(bool checked);

    void on_pushButton_11_toggled(bool checked);

    //void on_pushButton_2_clicked();

    //void on_pushButton_4_clicked();

    void on_logout_clicked();

    void on_logout_2_clicked();



    void on_pushButton_10_toggled(bool checked);

    void on_pushButton_16_toggled(bool checked);

    void on_pushButton_12_toggled(bool checked);

    void on_pushButton_18_toggled(bool checked);

    void on_pushButton_21_toggled(bool checked);

    void on_pushButton_20_toggled(bool checked);

    void on_pushButton_15_toggled(bool checked);

    void on_pushButton_13_toggled(bool checked);

    void on_pushButton_14_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // ADMIN_VIEW_H
