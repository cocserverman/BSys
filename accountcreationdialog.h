#ifndef ACCOUNTCREATIONDIALOG_H
#define ACCOUNTCREATIONDIALOG_H

#include <QDialog>
#include <QMap>
#include "User.h"
#include "Customer.h"
#include "ui_AccountCreationDialog.h"

class AccountCreationDialog : public QDialog {
    Q_OBJECT

public:
    AccountCreationDialog(QMap<QString, User*>& users, QWidget *parent = nullptr);

private slots:
    void createAccount();

private:
    Ui::AccountCreationDialog ui;
    QMap<QString, User*>& users;
};

#endif
