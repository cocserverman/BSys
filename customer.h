#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>
#include "user.h"

class Customer : public User
{
    Q_OBJECT
public:
    explicit Customer(QObject *parent = nullptr);
};

#endif // CUSTOMER_H
