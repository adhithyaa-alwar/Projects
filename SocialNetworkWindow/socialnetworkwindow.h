// socialnetworkwindow.h file by: Adhithyaa Arul Murugan Alwar
// This file is a header file for the SocialNetworkWindow class, connecting the code to the UI

#ifndef SOCIALNETWORKWINDOW_H
#define SOCIALNETWORKWINDOW_H

#include <QMainWindow>
#include "network.h"
#include <stack>

QT_BEGIN_NAMESPACE
namespace Ui { class SocialNetworkWindow; }
QT_END_NAMESPACE

class SocialNetworkWindow : public QMainWindow
{
    Q_OBJECT

public:
    SocialNetworkWindow(QWidget *parent = nullptr);
    ~SocialNetworkWindow();
    void loginButton();
    void profilePage();
    void clearTable();
    void shiftToFriendPage(int row, int column);
    void backToUserPage();
    void shiftToSuggestedFriend(int row, int column);
    void addFriend();
    void undoButton();
    void logoutAccepted();
    void logoutDenied();
private:
    Ui::SocialNetworkWindow *ui;
    Network budLinker;
    User* loggedInUser;
    User* currentUser;
    std::stack<User*> pageHistory;
};
#endif // SOCIALNETWORKWINDOW_H
