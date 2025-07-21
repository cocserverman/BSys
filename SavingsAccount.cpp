#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const QString& c, const QString& i, const QString& a, const QString& cvv, const QDate& ce, double b, const QString& p, const QString& sp, double r, const QDate& ae)
    : Account(c, i, a, cvv, ce, b, p, sp), profitRate(r), accountExpiryDate(ae) {}

QString SavingsAccount::getType() const { return "Savings"; }

double SavingsAccount::getProfitRate() const { return profitRate; }

QDate SavingsAccount::getAccountExpiryDate() const { return accountExpiryDate; }

void SavingsAccount::applyProfit() {
    if (!isAccountExpired()) balance += balance * profitRate;
}

bool SavingsAccount::isAccountExpired() const { return QDate::currentDate() > accountExpiryDate; }


