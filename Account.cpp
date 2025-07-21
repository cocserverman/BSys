#include "Account.h"
#include "Transaction.h"

Account::Account(const QString& c, const QString& i, const QString& a, const QString& cvv, const QDate& e, double b, const QString& p, const QString& sp)
    : cardNumber(c), iban(i), accountNumber(a), cvv2(cvv), expirationDate(e), balance(b), pin(p), staticSecondPass(sp) {}

QString Account::getCardNumber() const { return cardNumber; }
QString Account::getIBAN() const { return iban; }
QString Account::getAccountNumber() const { return accountNumber; }
QString Account::getCVV2() const { return cvv2; }
QDate Account::getExpirationDate() const { return expirationDate; }
double Account::getBalance() const { return balance; }
QString Account::getPin() const { return pin; }
QString Account::getStaticSecondPass() const { return staticSecondPass; }
QString Account::getDynamicSecondPass() const { return dynamicSecondPass; }

void Account::setPin(const QString& newPin) { pin = newPin; }
void Account::setStaticSecondPass(const QString& pass) { staticSecondPass = pass; }
void Account::setDynamicSecondPass(const QString& pass) {
    dynamicSecondPass = pass;
    dynamicGeneratedTime = QDateTime::currentDateTime();
}

bool Account::validatePin(const QString& input) const {
    return input == pin;
}

bool Account::validateSecondPass(const QString& input, bool isDynamic) {
    if (isDynamic) {
        bool valid = input == dynamicSecondPass;
        if (valid) dynamicSecondPass.clear();
        return valid;
    } else {
        return input == staticSecondPass;
    }
}

void Account::deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool Account::withdraw(double amount) {
    if (balance >= amount && amount > 0) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::applyProfit() {}
bool Account::isAccountExpired() const { return false; }

void Account::addTransaction(Transaction* t) {
    transactions.append(t);
}

QList<Transaction*> Account::getTransactions() const {
    return transactions;
}

double Account::getTransferredToday() const {
    double total = 0;
    QDate today = QDate::currentDate();
    for (Transaction* t : transactions) {
        if (t->getTimestamp().date() == today) {
            total += t->getAmount();
        }
    }
    return total;
}
