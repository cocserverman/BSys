#ifndef FINANCIALACC_H
#define FINANCIALACC_H

#include <QObject>

class FinancialAcc : public QObject
{
    Q_OBJECT
public:
    explicit FinancialAcc(QObject *parent = nullptr);
private:
    string CardNum;
    string AccNumber;
    string WireNumber;
    int CVV2;
    QDate CardExp;
    int MainPass;
    int StaticSecPass;
    int VariableSecPass;
    int balance;

signals:
};

#endif // FINANCIALACC_H
