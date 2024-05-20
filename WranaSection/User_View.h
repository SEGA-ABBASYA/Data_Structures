#ifndef USER_VIEW_H
#define USER_VIEW_H
#include <QList>
#include <QWidgetItem>
#include <QListWidgetItem>
#include <QWidget>
#include <QMap>
#include <user.h>

using namespace std;
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
    void search(const QString& text);

    void on_searchEdit_textChanged(const QString &arg1);
    void addFriend(QListWidgetItem *item);
    void updateFriendsList();
    void on_resultsList_itemClicked(QListWidgetItem *item);
    void removeFriend();
    void on_removeButton_clicked();
    void openChat();

    void on_directMessageButton_clicked();
    void updateNotifications();
    void refreshNotifications();

    void showData();
    void updateUserDetails(const string& oldUsername, const string& newName, const string& newEmail, int newId, int newAcademicYear, int newSection, const string& newUsername, const string& newPassword, const string& newProgram, char newGender);

    void on_editUserButton_clicked();

    void on_DM_3_clicked();

    void on_DM_4_clicked();

private:
    Ui::UserView *ui;

};

#endif // USER_VIEW_H
