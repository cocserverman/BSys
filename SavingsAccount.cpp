#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const QString& c, const QString& i, const QString& a, const QString& cvv, const QDate& ce, double b, const QString& p, const QString& sp, double r, const QDate& ae)
    : Account(c, i, a, cvv, ce, b, p, sp), profitRate(r), accountExpiryDate(ae) {}

QString getType() const { return "Savings"; }

double getProfitRate() const { return profitRate; }

QDate getAccountExpiryDate() const { return accountExpiryDate; }

bool isAccountExpired() const { return QDate::currentDate() > accountExpiryDate; }

void applyProfit() {
    if (!isAccountExpired()) balance += balance * profitRate;
}
