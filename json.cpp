#include "json.h"

JSON::JSON()
{

}

/**
 * @brief JSON::JsonToString
 * @param jsonObj
 * @return jsonStr
 */
QString JSON::JsonToString(const QJsonObject& jsonObj){
    return QString(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact));
}

/**
 * @brief JSON::StringToJson
 * @param jsonStr
 * @return jsonObj
 */
QJsonObject JSON::StringToJson(const QString& jsonStr){
    QJsonObject json;
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &err);
    if(err.error == QJsonParseError::NoError && doc.isObject()){
        json = doc.object();
    }
    return json;
}
