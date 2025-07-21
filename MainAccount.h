#ifndef MAINACCOUNT_H
#define MAINACCOUNT_H

#include "Account.h"

class MainAccount : public Account {
private:
    double profitRate=0.05;

public:
    MainAccount(const QString&, const QString&, const QString&, const QString&, const QDate&, double, const QString&, const QString&, double = 0.0005);
    QString getType() const override;
    double getProfitRate() const;
    void applyProfit() override;
};

#endif
