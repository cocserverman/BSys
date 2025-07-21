#ifndef TRANSFERFORM_H
#define TRANSFERFORM_H

#include <QWidget>
#include "Customer.h"
#include "ui_TransferForm.h"

class TransferForm : public QWidget {
    Q_OBJECT

public:
    TransferForm(Customer* customer, QWidget *parent = nullptr);

private slots:
    void makeTransfer();

private:
    Ui::TransferForm ui;
    Customer* customer;
};

#endif
