#include "PasswordChangeForm.h"
#include <QMessageBox>

PasswordChangeForm::PasswordChangeForm(Customer* customer, QWidget *parent)
    : QWidget(parent), customer(customer) {
    ui.setupUi(this);
    connect(ui.applyBtn, &QPushButton::clicked, this, &PasswordChangeForm::applyChanges);
}

void PasswordChangeForm::applyChanges() {
    QString newPin = ui.newPinEdit->text();
    QString newSecond = ui.newSecondPassEdit->text();

    if (customer->getAccounts().isEmpty()) return;

    for (Account* acc : customer->getAccounts()) {
        if (!newPin.isEmpty()) acc->setPin(newPin);
        if (!newSecond.isEmpty()) acc->setStaticSecondPass(newSecond);
    }

    QMessageBox::information(this, "Done", "Passwords updated.");
    this->close();
}
