// socialnetworkwindow.cpp file by: Adhithyaa Arul Murugan Alwar
// This file contains the implementation of the functions for the Social Network Window class

#include "socialnetworkwindow.h"
#include "ui_socialnetworkwindow.h"
#include <QStringList>
using namespace std;

// pre: Valid file names given and working network, post, incoming post, and user classes provided
// post: Shows the user interface, starting with the login page
SocialNetworkWindow::SocialNetworkWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::SocialNetworkWindow)
{
    ui->setupUi(this);
    char socialNetworkFileName[] = "social_network.txt";
    char postFileName[] = "posts.txt";
    budLinker.readUsers(socialNetworkFileName);
    budLinker.readPosts(postFileName);
    ui->backToProfile->hide();
    ui->profilePageLabel->hide();
    ui->friendList->hide();
    ui->recentPosts->hide();
    ui->suggestedFriends->hide();
    ui->addFriend->hide();
    ui->undoButton->hide();
    ui->yesLogout->hide();
    ui->noLogout->hide();
    ui->logoutQuestion->hide();
    ui->loginButton->setText(QString::fromStdString("Login"));
    ui->loginTextEdit->setText(QString::fromStdString(""));
    ui->loginLabel->setText(QString::fromStdString("Greetings friends, welcome to BudLinker, "
    "a social \n platform to link with friends, family and colleagues! \n Please enter your username to login!"));
    connect(ui->loginButton, &QPushButton::clicked, this, &SocialNetworkWindow::loginButton);
    connect(ui->friendList, &QTableWidget::cellClicked, this, &SocialNetworkWindow::shiftToFriendPage);
    connect(ui->backToProfile, &QPushButton::clicked, this, &SocialNetworkWindow::backToUserPage);
    connect(ui->suggestedFriends, &QTableWidget::cellClicked, this, &SocialNetworkWindow::shiftToSuggestedFriend);
    connect(ui->addFriend, &QPushButton::clicked, this, &SocialNetworkWindow::addFriend);
    connect(ui->undoButton, &QPushButton::clicked, this, &SocialNetworkWindow::undoButton);
    connect(ui->noLogout, &QPushButton::clicked, this, &SocialNetworkWindow::logoutDenied);
    connect(ui->yesLogout, &QPushButton::clicked, this, &SocialNetworkWindow::logoutAccepted);
}

// pre: None
// post: Class destructor
SocialNetworkWindow::~SocialNetworkWindow()
{
    delete ui;
}

// pre: None
// post: Checks if valid user is inputted and takes appropriate action
void SocialNetworkWindow::loginButton(){
    string userInput = ui->loginTextEdit->toPlainText().toStdString();
    if(userInput.size() == 0){
        ui->loginLabel->setText(QString::fromStdString("Greetings friends, welcome to BudLinker, "
        "a social \n platform to link with friends, family and colleagues! \n Please enter your username to login!"
        "\n No user inputted!"));
    }
    else if(budLinker.getId(userInput) == -1){
        ui->loginLabel->setText(QString::fromStdString("Greetings friends, welcome to BudLinker, "
        "a social \n platform to link with friends, family and colleagues! \n Please enter your username to login!"
        "\n Invalid User!"));
    }
    else{
        ui->loginButton->hide();
        ui->loginTextEdit->hide();
        ui->loginLabel->hide();
        ui->backToProfile->setText(QString::fromStdString("Back to Profile"));
        ui->undoButton->setText(QString::fromStdString("Logout"));
        loggedInUser = budLinker.getUser(budLinker.getId(userInput));
        currentUser = loggedInUser;
        profilePage();
    }
}

// pre: None
// post: Shows the profile page of currentUser
void SocialNetworkWindow::profilePage(){
    vector<size_t> friendIds = currentUser->getFriends();
    ui->addFriend->hide();
    ui->suggestedFriends->hide();
    size_t score = -1;
    size_t loggedInUserId = loggedInUser->getID();
    vector<size_t> suggestedFriendIds = budLinker.suggestFriends(loggedInUser->getID(), score);
    // Creates table with list of friends
    for(int i = 0; i < friendIds.size(); i++){
        if(i == 0){
            ui->friendList->insertColumn(i);
        }
        User* tempFriend = budLinker.getUser(friendIds[i]);
        QTableWidgetItem* friendName = new QTableWidgetItem;
        friendName->setText(QString::fromStdString(tempFriend->getFullName()));
        ui->friendList->insertRow(i);
        ui->friendList->setItem(i, 0, friendName);
    }
    // Case for if the user is on their own profile page
    if(loggedInUser == currentUser){
        ui->profilePageLabel->setText(QString::fromStdString("My Profile"));
        ui->recentPosts->setText(QString::fromStdString(currentUser->displayPosts(5, false)));
        ui->backToProfile->hide();
        ui->suggestedFriends->show();
        for(int i = 0; i < suggestedFriendIds.size(); i++){
            if(i == 0){
                ui->suggestedFriends->insertColumn(i);
            }
            User* tempFriend = budLinker.getUser(suggestedFriendIds[i]);
            QTableWidgetItem* friendName = new QTableWidgetItem;
            friendName->setText(QString::fromStdString(tempFriend->getFullName()));
            ui->suggestedFriends->insertRow(i);
            ui->suggestedFriends->setItem(i, 0, friendName);
        }
        QStringList suggestFriendlabel = {"Suggested Friends"};
        ui->suggestedFriends->setHorizontalHeaderLabels(suggestFriendlabel);
    }
    // Case if user is viewing other user's pages
    else{
        ui->profilePageLabel->setText(QString::fromStdString(currentUser->getFullName() + "'s Profile"));
        ui->recentPosts->setText(QString::fromStdString(currentUser->displayPosts(5, true)));
        ui->backToProfile->show();
        for(int i = 0; i < friendIds.size(); i++){
            if(friendIds[i] == loggedInUserId){
                break;
            }
            else if(i == friendIds.size() - 1){
                ui->addFriend->show();
            }
        }

    }
    QStringList label = {"Friends"};
    ui->friendList->setHorizontalHeaderLabels(label);
    ui->profilePageLabel->show();
    ui->friendList->show();
    ui->recentPosts->show();
    ui->undoButton->show();
}

// pre: None
// post: Removes all the information in the friend list and the suggested friends qtable widgets
void SocialNetworkWindow::clearTable(){
    ui->friendList->setRowCount(0);
    ui->friendList->setColumnCount(0);
    ui->friendList->clear();
    ui->suggestedFriends->setRowCount(0);
    ui->suggestedFriends->setColumnCount(0);
    ui->suggestedFriends->clear();
}

// pre: None
// post: Moves to the clicked user's profile page
void SocialNetworkWindow::shiftToFriendPage(int row, int column){
    if(pageHistory.empty()){
        ui->undoButton->setText(QString::fromStdString("Go Back to Previous Page"));
    }
    User* tempUser = currentUser;
    pageHistory.push(tempUser);
    currentUser = budLinker.getUser(budLinker.getId(ui->friendList->item(row,column)->text().toStdString()));
    clearTable();
    profilePage();
}

// pre: None
// post: Moves back to the logged in user's profile page
void SocialNetworkWindow::backToUserPage(){
    User* tempUser = currentUser;
    pageHistory.push(tempUser);
    currentUser = loggedInUser;
    clearTable();
    profilePage();
}

// pre: None
// post: Shifts to the suggested friend's page when specified row and column is clicked
void SocialNetworkWindow::shiftToSuggestedFriend(int row, int column){
    if(pageHistory.empty()){
        ui->undoButton->setText(QString::fromStdString("Go Back to Previous Page"));
    }
    User* tempUser = currentUser;
    pageHistory.push(tempUser);
    currentUser = budLinker.getUser(budLinker.getId(ui->suggestedFriends->item(row,column)->text().toStdString()));
    clearTable();
    profilePage();
}

// pre: None
// post: Makes two users friends
void SocialNetworkWindow::addFriend(){
    budLinker.addConnection(currentUser->getFullName(), loggedInUser->getFullName());
    ui->addFriend->hide();
    clearTable();
    profilePage();
}

// pre: None
// post: Goes back to the previous page the user was on
void SocialNetworkWindow::undoButton(){
    if(!pageHistory.empty()){
        currentUser = pageHistory.top();
        clearTable();
        profilePage();
        pageHistory.pop();
        if(pageHistory.empty()){
            ui->undoButton->setText(QString::fromStdString("Logout"));
        }
    }
    else{
        ui->profilePageLabel->hide();
        ui->friendList->hide();
        ui->recentPosts->hide();
        ui->suggestedFriends->hide();
        ui->undoButton->hide();
        ui->logoutQuestion->show();
        ui->yesLogout->show();
        ui->noLogout->show();
    }
}

// pre: The Yes Button is clicked when the user is asked whether they want to logout
// post: Logs out the user, resets loggedInUser value and goes back to original login page
void SocialNetworkWindow::logoutAccepted(){
    loggedInUser = nullptr;
    currentUser = nullptr;
    clearTable();
    ui->backToProfile->hide();
    ui->profilePageLabel->hide();
    ui->friendList->hide();
    ui->recentPosts->hide();
    ui->suggestedFriends->hide();
    ui->addFriend->hide();
    ui->undoButton->hide();
    ui->yesLogout->hide();
    ui->noLogout->hide();
    ui->logoutQuestion->hide();
    ui->loginButton->setText(QString::fromStdString("Login"));
    ui->loginTextEdit->setText(QString::fromStdString(""));
    ui->loginButton->show();
    ui->loginTextEdit->show();
    ui->loginLabel->show();
    loginButton();
    ui->loginLabel->setText(QString::fromStdString("Greetings friends, welcome to BudLinker, "
    "a social \n platform to link with friends, family and colleagues! \n Please enter your username to login!"));

}

// pre: The No Button is clicked when the user is asked whether they want to logout
// post: Displays user's profile and hides question
void SocialNetworkWindow::logoutDenied(){
    ui->profilePageLabel->show();
    ui->friendList->show();
    ui->recentPosts->show();
    ui->suggestedFriends->show();
    ui->undoButton->show();
    ui->logoutQuestion->hide();
    ui->yesLogout->hide();
    ui->noLogout->hide();
}
