#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDateTime>

class Transaction {
private:
    QString sourceCard;
    QString destCard;
    double amount;
    QDateTime timestamp;

public:
    Transaction(const QString&, const QString&, double);
    QString getSourceCard() const;
    QString getDestCard() const;
    double getAmount() const;
    QDateTime getTimestamp() const;
};

#endif
