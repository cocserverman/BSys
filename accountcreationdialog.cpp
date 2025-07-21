#include "AccountCreationDialog.h"
#include "MainAccount.h"
#include "SavingsAccount.h"
#include "NonProfitAccount.h"
#include <QMessageBox>

AccountCreationDialog::AccountCreationDialog(QMap<QString, User*>& users, QWidget *parent)
    : QDialog(parent), users(users) {
    ui.setupUi(this);
    connect(ui.createBtn, &QPushButton::clicked, this, &AccountCreationDialog::createAccount);
}

void AccountCreationDialog::createAccount() {
    QString username = ui.usernameEdit->text();
    QString type = ui.accountTypeCombo->currentText();
    double balance = ui.balanceEdit->text().toDouble();

    if (!users.contains(username)) {
        QMessageBox::warning(this, "Error", "User not found.");
        return;
    }

    Customer* customer = dynamic_cast<Customer*>(users[username]);
    if (!customer) {
        QMessageBox::warning(this, "Error", "Only customers can have accounts.");
        return;
    }

    if (!customer->canAddMoreAccounts()) {
        QMessageBox::warning(this, "Error", "Max 5 accounts reached.");
        return;
    }

    QString card = "411122223333" + QString::number(Qrand() % 10000).rightJustified(4, '0');
    QString iban = "IR" + QString::number(1000000 + Qrand() % 8999999);
    QString acc = "ACC" + QString::number(Qrand() % 99999);
    QString cvv = QString::number(100 + Qrand() % 899);
    QDate exp = QDate::currentDate().addYears(3);
    QString pin = "1234";
    QString pass = "5678";

    Account* account = nullptr;

    if (type == "Main") {
        account = new MainAccount(card, iban, acc, cvv, exp, balance, pin, pass);
    } else if (type == "Savings") {
        account = new SavingsAccount(card, iban, acc, cvv, exp, balance, pin, pass, 0.02, QDate::currentDate().addYears(2));
    } else {
        account = new NonProfitAccount(card, iban, acc, cvv, exp, balance, pin, pass);
    }

    customer->addAccount(account);
    QMessageBox::information(this, "Success", "Account created.");
    this->accept();
}
