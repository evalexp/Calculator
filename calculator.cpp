#include "calculator.h"
#include "QString"
#include "tinyexpr.h"
#include "evaluator.h"
#include "QDebug"

Calculator::Calculator()
{

}

double Calculator::eval(QString exp){
//    return te_interp(exp.toStdString().c_str(), 0);
    Evaluator* e = new Evaluator();
    double result = e->eval(exp);
    delete e;
    return result;
}
