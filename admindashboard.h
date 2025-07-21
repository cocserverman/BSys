#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QWidget>
#include <QMap>
#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "ui_AdminDashboard.h"

class AdminDashboard : public QWidget {
    Q_OBJECT

public:
    AdminDashboard(Admin* admin, QMap<QString, User*>& users, QWidget *parent = nullptr);

private slots:
    void showUserList();
    void showCreateAccountDialog();

private:
    Ui::AdminDashboard ui;
    Admin* admin;
    QMap<QString, User*>& users;
};

#endif
