#include "CustomerDashboard.h"
#include <QMessageBox>

CustomerDashboard::CustomerDashboard(Customer* customer, QWidget *parent)
    : QWidget(parent), customer(customer) {
    ui.setupUi(this);
    ui.welcomeLabel->setText("Welcome, " + customer->getFullName());
    showAccounts();

    connect(ui.viewDetailsBtn, &QPushButton::clicked, this, &CustomerDashboard::viewDetails);
    connect(ui.transferBtn, &QPushButton::clicked, this, &CustomerDashboard::openTransferForm);
    connect(ui.changePasswordBtn, &QPushButton::clicked, this, &CustomerDashboard::openPasswordChange);
    connect(ui.logoutBtn, &QPushButton::clicked, this, &QWidget::close);
}

void showAccounts() {
    ui.accountList->clear();
    for (Account* acc : customer->getAccounts()) {
        ui.accountList->addItem(acc->getType() + " - " + acc->getCardNumber());
    }
}

void viewDetails() {
    int idx = ui.accountList->currentRow();
    if (idx < 0 || idx >= customer->getAccounts().size()) return;

    Account* acc = customer->getAccounts()[idx];
    QString info = "Card: " + acc->getCardNumber() + "\nBalance: " + QString::number(acc->getBalance());
    QMessageBox::information(this, "Account Info", info);
}

void openTransferForm() {
    TransferForm* form = new TransferForm(customer);
    form->show();
}

void openPasswordChange() {
    PasswordChangeForm* form = new PasswordChangeForm(customer);
    form->show();
}
