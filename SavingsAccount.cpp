#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const QString& c, const QString& i, const QString& a, const QString& cvv, const QDate& ce, double b, const QString& p, const QString& sp, double r, const QDate& ae)
    : Account(c, i, a, cvv, ce, b, p, sp), profitRate(r), accountExpiryDate(ae) {}

QString SavingsAccount::getType()  { return "Savings"; }

double SavingsAccount::getProfitRate()  { return profitRate; }

QDate SavingsAccount::getAccountExpiryDate() { return accountExpiryDate; }

bool SavingsAccount::isAccountExpired() { return QDate::currentDate() > accountExpiryDate; }

void SavingsAccount::applyProfit() {
    if (!isAccountExpired()) balance += balance * profitRate;
}
