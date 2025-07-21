#include "Admin.h"

Admin::Admin(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password)
    : User(firstName,lasName,nationalID,age,username,password) {}
QString getRole() const {
    return "Admin";
}

