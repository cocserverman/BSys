#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QObject>
#include "user.h"

class Customer : private User
{
    Q_OBJECT
public:
    explicit Customer(QObject *parent = nullptr);
private:

};

#endif // CUSTOMER_H
