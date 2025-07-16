#ifndef USER_H
#define USER_H

#include <string>
#include <QObject>

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

signals:
};

#endif // USER_H
