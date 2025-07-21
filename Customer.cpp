#include "Customer.h"

Customer::Customer(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password)
: User(firstName, lastName, nationalID, age, username, password) {}

QString Customer::getRole() {
    return "Customer";
}
QVector<Account*>& Customer::getAccounts() {
    return account;
}
bool Customer::canAddMoreAccounts() const {
    return accounts.size() <5;
}
void Customer::addAccount(Account* account) {
    if(canAddMoreAccounts){
        accounts.append(account);
    }
}

