#ifndef USER_VIEW_H
#define USER_VIEW_H
#include <QList>
#include <QWidgetItem>
#include <QListWidgetItem>
#include <QWidget>
#include<user.h>
#include<database.h>
#include<QRegularExpression>

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

    void on_pushButton_toggled(bool checked);

    void on_pushButton_2_toggled(bool checked);


    void on_logouticons_clicked();

    void on_logoutfull_clicked();

    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_DM_clicked();

   void on_add_button_clicked();

    void on_delete_button_clicked();



    void on_text_filter_textChanged(const QString &arg1);

    void on_text_filter_2_textChanged(const QString &arg1);

private:
    Ui::UserView *ui;
};

#endif // USER_VIEW_H
