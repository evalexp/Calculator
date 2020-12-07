#include "calculator.h"
#include "QString"
#include "tinyexpr.h"

Calculator::Calculator()
{

}

double Calculator::eval(QString exp){
    return te_interp(exp.toStdString().c_str(), 0);
}
