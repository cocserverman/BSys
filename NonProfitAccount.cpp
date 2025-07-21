#include "NonProfitAccount.h"

NonProfitAccount:: NonProfitAccount(const QString&, const QString&, const QString&, const QString&, const QDate&, double, const QString&, const QString&)
    : Account(cardNumber, iban,accountNumber,cvv2,expirationDate,balance,pin,staticSecondPass) {}

QString NonProfitAccount::getType() const { return "NonProfitAccount"; }

void NonProfitAccount::applyProfit() {}
