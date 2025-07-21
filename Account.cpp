#include "Account.h"
#include "Transaction.h"

Account::Account(const QString& c, const QString& i, const QString& a, const QString& cvv, const QDate& e, double b, const QString& p, const QString& sp)
    : cardNumber(c), iban(i), accountNumber(a), cvv2(cvv), expirationDate(e), balance(b), pin(p), staticSecondPass(sp) {}

QString getCardNumber() const { return cardNumber; }
QString getIBAN() const { return iban; }
QString getAccountNumber() const { return accountNumber; }
QString getCVV2() const { return cvv2; }
QDate getExpirationDate() const { return expirationDate; }
double getBalance() const { return balance; }
QString getPin() const { return pin; }
QString getStaticSecondPass() const { return staticSecondPass; }
QString getDynamicSecondPass() const { return dynamicSecondPass; }

void setPin(const QString& newPin) { pin = newPin; }
void setStaticSecondPass(const QString& pass) { staticSecondPass = pass; }
void setDynamicSecondPass(const QString& pass) {
    dynamicSecondPass = pass;
    dynamicGeneratedTime = QDateTime::currentDateTime();
}

bool validatePin(const QString& input) const {
    return input == pin;
}

bool validateSecondPass(const QString& input, bool isDynamic) {
    if (isDynamic) {
        bool valid = input == dynamicSecondPass;
        if (valid) dynamicSecondPass.clear();
        return valid;
    } else {
        return input == staticSecondPass;
    }
}

void deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool withdraw(double amount) {
    if (balance >= amount && amount > 0) {
        balance -= amount;
        return true;
    }
    return false;
}

void applyProfit() {}
bool isAccountExpired() const { return false; }

void addTransaction(Transaction* t) {
    transactions.append(t);
}

QList<Transaction*> getTransactions() const {
    return transactions;
}

double getTransferredToday() const {
    double total = 0;
    QDate today = QDate::currentDate();
    for (Transaction* t : transactions) {
        if (t->getTimestamp().date() == today) {
            total += t->getAmount();
        }
    }
    return total;
}
