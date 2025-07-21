#ifndef NonProfitAccount_H
#define NonProfitAccount_H

#include "Account.h"

class NonProfitAccount : public Account {
public:
    NonProfitAccount(const QString&, const QString&, const QString&, const QString&, const QDate&, double, const QString&, const QString&);
    using Account::Account;
    QString getType() const override;
    void applyProfit() override;
};

#endif
