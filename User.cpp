#include "User.h"

User::User(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password)
    : firstName(firstName),lastName(lastName),nationalID(nationalID),age(age),username(username),password(password) {}

QString User::getUsername() const {
    return username;
}
QString User::getPassword() const {
    return password;
}
QString User::getFullName() const {
    return firstName + " " + lastName;
}
QString User::getNationalID() const {
    return nationalID;
}
int User::getAge() const {
    return age;
}

