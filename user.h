#ifndef USER_H
#define USER_H

#include <QObject>
#include <string>
#include"financialacc.h"

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
private:
    string Name;
    string FamilyName;
    string SocialCode;
    int age;
    string UserName;
    string Password;
    //*ACC?
signals:
};

#endif // USER_H
