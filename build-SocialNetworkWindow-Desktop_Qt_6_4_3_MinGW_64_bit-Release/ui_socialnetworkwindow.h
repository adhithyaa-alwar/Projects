/********************************************************************************
** Form generated from reading UI file 'socialnetworkwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOCIALNETWORKWINDOW_H
#define UI_SOCIALNETWORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SocialNetworkWindow
{
public:
    QWidget *centralwidget;
    QLabel *loginLabel;
    QPushButton *loginButton;
    QTextEdit *loginTextEdit;
    QLabel *profilePageLabel;
    QTableWidget *friendList;
    QLabel *recentPosts;
    QPushButton *backToProfile;
    QTableWidget *suggestedFriends;
    QPushButton *addFriend;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SocialNetworkWindow)
    {
        if (SocialNetworkWindow->objectName().isEmpty())
            SocialNetworkWindow->setObjectName("SocialNetworkWindow");
        SocialNetworkWindow->resize(800, 600);
        centralwidget = new QWidget(SocialNetworkWindow);
        centralwidget->setObjectName("centralwidget");
        loginLabel = new QLabel(centralwidget);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(190, 50, 381, 61));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(340, 190, 80, 24));
        loginTextEdit = new QTextEdit(centralwidget);
        loginTextEdit->setObjectName("loginTextEdit");
        loginTextEdit->setGeometry(QRect(180, 130, 391, 31));
        profilePageLabel = new QLabel(centralwidget);
        profilePageLabel->setObjectName("profilePageLabel");
        profilePageLabel->setGeometry(QRect(240, 10, 191, 20));
        friendList = new QTableWidget(centralwidget);
        friendList->setObjectName("friendList");
        friendList->setGeometry(QRect(620, 0, 161, 192));
        recentPosts = new QLabel(centralwidget);
        recentPosts->setObjectName("recentPosts");
        recentPosts->setGeometry(QRect(120, 50, 471, 251));
        backToProfile = new QPushButton(centralwidget);
        backToProfile->setObjectName("backToProfile");
        backToProfile->setGeometry(QRect(10, 280, 101, 24));
        suggestedFriends = new QTableWidget(centralwidget);
        suggestedFriends->setObjectName("suggestedFriends");
        suggestedFriends->setGeometry(QRect(620, 200, 161, 131));
        addFriend = new QPushButton(centralwidget);
        addFriend->setObjectName("addFriend");
        addFriend->setGeometry(QRect(20, 10, 80, 24));
        SocialNetworkWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SocialNetworkWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        SocialNetworkWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SocialNetworkWindow);
        statusbar->setObjectName("statusbar");
        SocialNetworkWindow->setStatusBar(statusbar);

        retranslateUi(SocialNetworkWindow);

        QMetaObject::connectSlotsByName(SocialNetworkWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SocialNetworkWindow)
    {
        SocialNetworkWindow->setWindowTitle(QCoreApplication::translate("SocialNetworkWindow", "SocialNetworkWindow", nullptr));
        loginLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "loginLabel", nullptr));
        loginButton->setText(QCoreApplication::translate("SocialNetworkWindow", "loginButton", nullptr));
        loginTextEdit->setHtml(QCoreApplication::translate("SocialNetworkWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">loginTextEdit</p></body></html>", nullptr));
        profilePageLabel->setText(QCoreApplication::translate("SocialNetworkWindow", "profilePageLabel", nullptr));
        recentPosts->setText(QCoreApplication::translate("SocialNetworkWindow", "recentPosts", nullptr));
        backToProfile->setText(QCoreApplication::translate("SocialNetworkWindow", "backToProfile", nullptr));
        addFriend->setText(QCoreApplication::translate("SocialNetworkWindow", "Add Friend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SocialNetworkWindow: public Ui_SocialNetworkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOCIALNETWORKWINDOW_H
