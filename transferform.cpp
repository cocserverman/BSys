#include "TransferForm.h"
#include "Transaction.h"
#include <QMessageBox>

TransferForm::TransferForm(Customer* customer, QWidget *parent)
    : QWidget(parent), customer(customer) {
    ui.setupUi(this);

    for (Account* acc : customer->getAccounts()) {
        ui.sourceAccountCombo->addItem(acc->getCardNumber());
    }

    connect(ui.transferBtn, &QPushButton::clicked, this, &TransferForm::makeTransfer);
}

void TransferForm::makeTransfer() {
    int idx = ui.sourceAccountCombo->currentIndex();
    if (idx < 0 || idx >= customer->getAccounts().size()) return;

    Account* source = customer->getAccounts()[idx];
    QString destCard = ui.destCardEdit->text();
    double amount = ui.amountEdit->text().toDouble();
    QString pass = ui.secondPassEdit->text();

    if (source->getExpirationDate() < QDate::currentDate()) {
        QMessageBox::warning(this, "Error", "Card is expired.");
        return;
    }

    if (amount > 3000000) {
        QMessageBox::warning(this, "Error", "Max 3 million per transaction.");
        return;
    }

    if (source->getTransferredToday() + amount > 6000000) {
        QMessageBox::warning(this, "Error", "Max 6 million per day exceeded.");
        return;
    }

    bool useDynamic = amount > 100000;
    if (!source->validateSecondPass(pass, useDynamic)) {
        QMessageBox::warning(this, "Error", "Invalid second password.");
        return;
    }

    double fee = amount * 0.01;
    if (!source->withdraw(amount + fee)) {
        QMessageBox::warning(this, "Error", "Insufficient balance.");
        return;
    }

    Transaction* tx = new Transaction(source->getCardNumber(), destCard, amount);
    source->addTransaction(tx);

    QMessageBox::information(this, "Success", "Transfer successful.");
    this->close();
}
