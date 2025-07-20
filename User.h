#ifndef USER_H
#define USER_H

#include <string>
#include"Account.h"

class User
{
protected:
    QString firstName;
    QString lastName;
    QString nationalID;
    int age;
    QString username;
    QString password;
public:
    User(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password);
    virtual ~User()= default;
    QString getUsername() const;
    QString getPassword() const;
    QString getFullName() const;
    QString getNationalID() const;
    int getAge() const;

    virtual QString getRole() const=0;

};

#endif // USER_H
