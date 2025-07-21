#ifndef CUSTOMERDASHBOARD_H
#define CUSTOMERDASHBOARD_H

#include <QWidget>
#include "Customer.h"
#include "ui_CustomerDashboard.h"
#include "TransferForm.h"
#include "PasswordChangeForm.h"

class CustomerDashboard : public QWidget {
    Q_OBJECT

public:
    CustomerDashboard(Customer* customer, QWidget *parent = nullptr);

private slots:
    void showAccounts();
    void viewDetails();
    void openTransferForm();
    void openPasswordChange();

private:
    Ui::CustomerDashboard ui;
    Customer* customer;
};

#endif
