#include "MainAccount.h"

MainAccount::MainAccount(const QString& c, const QString& i, const QString& a, const QString& cvv, const QDate& e, double b, const QString& p, const QString& sp, double r)
    : Account(c, i, a, cvv, e, b, p, sp), profitRate(r) {}

QString getType() const { return "Main"; }

double getProfitRate() const { return profitRate; }

void applyProfit() { balance += balance * profitRate; }
