#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "QString"
#include <functional>
#include "QStringList"
#include "QList"
#include "QMap"
#include "cmath"

class Evaluator
{
public:
    Evaluator();

    double eval(QString);

    QString evalFunction(QString);
    QString evalParentheses(QString);
    QString evalMul(QString);
    QString evalPlus(QString);

private:
    bool isNumber(const QString&);
    QMap<QString, std::function<double (QList<double>)>> re_function;

    bool registerFunction(QString, std::function<double (QList<double>)>);
    QString stripSpace(QString);

    QStringList functionList;

    int FindMatchedIndex(const QString&, const int&);
    int FindForward(const QString&, const int&);
    int FindAfter(const QString&, const int&);
    void GetNumberAndIndex(const QString&, QString&, QString&, int&, int&, const int&);
};

#endif // EVALUATOR_H
