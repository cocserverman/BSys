#include "Transaction.h"

Transaction::Transaction(const QString& src, const QString& dst, double amt)
    : sourceCard(src), destCard(dst), amount(amt), timestamp(QDateTime::currentDateTime()) {}

QString Transaction::getSourceCard() const { return sourceCard; }
QString Transaction::getDestCard() const { return destCard; }
double Transaction::getAmount() const { return amount; }
QDateTime Transaction::getTimestamp() const { return timestamp; }
