#include "Admin.h"

Admin::Admin(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password)
    : User(firstName,lastName,nationalID,age,username,password) {}
QString Admin::getRole() const {
    return "Admin";
}
