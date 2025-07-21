#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDate>
#include <QList>

class Transaction;

class Account {
protected:
    QString cardNumber;
    QString iban;
    QString accountNumber;
    QString cvv2;
    QDate expirationDate;
    double balance;
    QString pin;
    QString staticSecondPass;
    QString dynamicSecondPass;
    QDateTime dynamicGeneratedTime;
    QList<Transaction*> transactions;

public:
    Account(const QString&, const QString&, const QString&, const QString&, const QDate&, double, const QString&, const QString&);
    virtual ~Account() = default;

    QString getCardNumber() const;
    QString getIBAN() const;
    QString getAccountNumber() const;
    QString getCVV2() const;
    QDate getExpirationDate() const;
    double getBalance() const;
    QString getPin() const;
    QString getStaticSecondPass() const;
    QString getDynamicSecondPass() const;
    void setPin(const QString&);
    void setStaticSecondPass(const QString&);
    void setDynamicSecondPass(const QString&);
    bool validatePin(const QString&) const;
    bool validateSecondPass(const QString&, bool isDynamic);
    virtual QString getType() const = 0;
    void deposit(double);
    bool withdraw(double);
    virtual void applyProfit();
    virtual bool isAccountExpired() const;
    double getTransferredToday() const;
    void addTransaction(Transaction*);
    QList<Transaction*> getTransactions() const;
};

#endif
