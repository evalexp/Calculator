#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "QString"

class Calculator
{
public:
    Calculator();
    static double eval(QString exp);
};

#endif // CALCULATOR_H
