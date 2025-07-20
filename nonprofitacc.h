#ifndef NONPROFITACC_H
#define NONPROFITACC_H

#include <QObject>
#include "Account.h"

class NonprofitAcc : public FinancialAcc
{
    Q_OBJECT
public:
    explicit NonprofitAcc(QObject *parent = nullptr);
};

#endif // NONPROFITACC_H
