#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H
#include <QMainWindow>
#include <string>
#include <vector>
#include <QList>
#include <QWidgetItem>
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QWidget>

using namespace std;

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
    void Write_graph_list_add();
    void Write_graph_list_delete();
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

    void on_pushButton_15_toggled(bool checked);

    void on_pushButton_13_toggled(bool checked);

    void on_pushButton_14_toggled(bool checked);


    /////////////////////////////Course/////////////////////////
    void on_pushButton_clicked();
    void on_tableWidget_3_itemClicked(QTableWidgetItem *item);
    void on_Delete_clicked();
    bool encodeValues(string hasLabOrSection);
    vector<string> disectStringEnter(string str);
    vector<string> disectStringComma(string str);
    void on_Edit_clicked();
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    ///////////////////////////User////////////////////////////
    void on_Add_clicked();
    void on_tableWidget_4_itemClicked(QTableWidgetItem *item);
    void on_deleteStudent_clicked();
    void on_tableWidget_2_itemClicked(QTableWidgetItem *item);
    void on_EditStudent_clicked();

    //////////////////////////Graph////////////////////////////
    void on_add_Graph_list_itemClicked(QListWidgetItem *item);

    void on_add_graph_Btn_clicked();

    void on_delete_Graph_list_itemClicked(QListWidgetItem *item);

    void on_Delete_2_clicked();

    void on_Edit_2_clicked();
    void on_Schedule_2_cellDoubleClicked(int row, int column);






private:
    Ui::MainWindow *ui;
};
#endif // ADMIN_VIEW_H
