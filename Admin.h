#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
public:
    Admin(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password);
    QString getRole() const override;
};

#endif // ADMIN_H
