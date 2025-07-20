#ifndef MAINACC_H
#define MAINACC_H

#include <QObject>
#include "Account.h"

class MainAcc : public FinancialAcc
{
    Q_OBJECT
public:
    explicit MainAcc(QObject *parent = nullptr);
    double IntRate;
};

#endif // MAINACC_H
