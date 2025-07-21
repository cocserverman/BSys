#include "AdminDashboard.h"
#include <QMessageBox>

AdminDashboard::AdminDashboard(Admin* admin, QMap<QString, User*>& users, QWidget *parent)
    : QWidget(parent), admin(admin), users(users) {
    ui.setupUi(this);
    ui.welcomeLabel->setText("Welcome, " + admin->getFullName());
    connect(ui.viewUsersBtn, &QPushButton::clicked, this, &AdminDashboard::showUserList);
    connect(ui.createAccountBtn, &QPushButton::clicked, this, &AdminDashboard::showCreateAccountDialog);
    connect(ui.logoutBtn, &QPushButton::clicked, this, &QWidget::close);
}

void AdminDashboard::showUserList() {
    QString list;
    for (auto user : users) {
        list += user->getFullName() + " - " + user->getRole() + "\n";
    }
    QMessageBox::information(this, "User List", list);
}

void AdminDashboard::showCreateAccountDialog() {
    QMessageBox::information(this, "Create Account", "Account creation UI not implemented here.");
}
