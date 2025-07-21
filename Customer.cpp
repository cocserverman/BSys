#include "Customer.h"
#include"Account.h"

Customer::Customer(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password)
: User(firstName, lastName, nationalID, age, username, password) {}

QString Customer::getRole() const {
    return "Customer";
}
QVector<Account*>& Customer::getAccounts() {
    return this->accounts;
}
bool Customer::canAddMoreAccounts() {
    return accounts.size() <5;
}
void Customer::addAccount(Account* account) {
    if(Customer::canAddMoreAccounts()){
        accounts.append(account);
    }
}

