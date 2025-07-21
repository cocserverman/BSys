#include "Transaction.h"

Transaction::Transaction(const QString& src, const QString& dst, double amt)
    : sourceCard(src), destCard(dst), amount(amt), timestamp(QDateTime::currentDateTime()) {}

QString getSourceCard() const { return sourceCard; }
QString getDestCard() const { return destCard; }
double getAmount() const { return amount; }
QDateTime getTimestamp() const { return timestamp; }
