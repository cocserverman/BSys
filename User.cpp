#include "User.h"

User::User(const QString& firstName,const QString& lastName,const QString& nationalID,int age,const QString& username,const QString& password)
    : firstName(firstName),lastName(lastName),nationalID(nationalID),age(age),username(username),password(password) {}

QString getUsername() const {
    return username;
}
QString getPassword() const {
    return password;
}
QString getFullName() const {
    return firstName + " " + lastName;
}
QString getNationalID() const {
    return nationalID;
}
int getAge() const {
    return age;
}

