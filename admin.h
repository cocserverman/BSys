#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include "User.h"
#include <string>

class Admin : private User
{
    Q_OBJECT
public:
    explicit Admin(QObject *parent = nullptr);

};

#endif // ADMIN_H
