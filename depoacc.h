#ifndef DEPOACC_H
#define DEPOACC_H

#include <QObject>
#include "Account.h"

class DepoAcc : public FinancialAcc
{
    Q_OBJECT
public:
    explicit DepoAcc(QObject *parent = nullptr);
    QDate AccEXP;
    double IntRate;
};

#endif // DEPOACC_H
