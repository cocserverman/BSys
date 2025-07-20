#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>

class FinancialAcc {
protected:
    QString cardNumber;
    QString iban;
    QString accountNumber;
    QString cvv2;
    QDate expirationDate; //for card
    double balance;
    QString pin; //first pin
    QString staticSecondPass;
    QString dynamicSecondPass;
public:



};

#endif // ACCOUNT_H
