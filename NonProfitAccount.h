#ifndef NonProfitAccount_H
#define NonProfitAccount_H

#include "Account.h"

class NonProfitAccount : public Account {
public:
    using Account::Account;
    QString getType() const override;
    void applyProfit() override;
};

#endif
