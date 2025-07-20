#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Account.h"
#include <QVector>

class Customer : public User
{
private:
    QVector<Account*> accounts;

public:
    Customer(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password);

    QString getRole() const override;
    QVector<Account*>& getAccounts();
    void addAccount(Account* account);
    bool canAddMoreAccounts() const;

};

#endif // CUSTOMER_H
