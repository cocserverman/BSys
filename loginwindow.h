#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "AdminDashboard.h"
#include "CustomerDashboard.h"
#include "Admin.h"
#include "Customer.h"
#include "ui_Loginwindow.h"
#include <QMap>

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void handleLogin();

private:
    Ui::Loginwindow ui;
    AdminDashboard* adminDashboard;
    CustomerDashboard* customerDashboard;
    QMap<QString, User*> users;

    void loadSampleData();
};

#endif
