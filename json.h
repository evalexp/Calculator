#ifndef JSON_H
#define JSON_H

#include "QJsonDocument"
#include "QJsonObject"

class JSON
{
public:
    JSON();
    static QString JsonToString(const QJsonObject&);
    static QJsonObject StringToJson(const QString&);
};

#endif // JSON_H
