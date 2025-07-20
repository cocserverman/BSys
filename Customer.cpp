#include "Customer.h"

Customer::Customer(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password)
: User(firstName, lastName, nationalID, age, username, password) {}

QString getRole() const {
    return "Customer";
}
QVector<Account*>& getAccounts() {
    return accounts;
}
void addAccount(Account* account) {
    if(canAddMoreAccounts){
        accounts.append(account);
    }
}
bool canAddMoreAccounts() const {
    return accounts.size() <5;
}
