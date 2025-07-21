#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double profitRate=0.08;
    QDate accountExpiryDate;

public:
    SavingsAccount(const QString&, const QString&, const QString&, const QString&, const QDate&, double, const QString&, const QString&, double, const QDate&);
    QString getType() const override;
    double getProfitRate() const;
    QDate getAccountExpiryDate() const;
    bool isAccountExpired() const override;
    void applyProfit() override;
};

#endif
