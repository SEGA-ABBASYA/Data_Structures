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
    ~AdminView();


private slots:

    void on_Test_toggled();


    void on_course_icon_toggled(bool checked);

    void on_graph_icon_toggled(bool checked);

    void on_student_icon_toggled(bool checked);

    void on_schedule_icon_toggled(bool checked);

    void on_Test_2_toggled();

private:
    Ui::MainWindow *ui;
};
#endif // ADMIN_VIEW_H
