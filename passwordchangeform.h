#ifndef PASSWORDCHANGEFORM_H
#define PASSWORDCHANGEFORM_H

#include <QWidget>
#include "Customer.h"
#include "ui_PasswordChangeForm.h"

class PasswordChangeForm : public QWidget {
    Q_OBJECT

public:
    PasswordChangeForm(Customer* customer, QWidget *parent = nullptr);

private slots:
    void applyChanges();

private:
    Ui::PasswordChangeForm ui;
    Customer* customer;
};

#endif
