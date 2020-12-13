#include "evaluator.h"
#include "QDebug"

Evaluator::Evaluator()
{
    /**
      * Register function sqrt
      */
    this->registerFunction("abs", [](QList<double> list) -> double{
        if(list.length() == 1){
            return fabs(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function acos
      */
    this->registerFunction("acos", [](QList<double> list) -> double{
        if(list.length() == 1){
            return acos(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function asin
      */
    this->registerFunction("asin", [](QList<double> list) -> double{
        if(list.length() == 1){
            return asin(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function atan
      */
    this->registerFunction("atan", [](QList<double> list) -> double{
        if(list.length() == 1){
            return atan(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function atan2
      */
    this->registerFunction("atan2", [](QList<double> list) -> double{
        if(list.length() == 2){
            return atan2(list[0], list[1]);
        }else{
            throw "require 2 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function ceil
      */
    this->registerFunction("ceil", [](QList<double> list) -> double{
        if(list.length() == 1){
            return ceil(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function cos
      */
    this->registerFunction("cos", [](QList<double> list) -> double{
        if(list.length() == 1){
            return cos(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function cosh
      */
    this->registerFunction("cosh", [](QList<double> list) -> double{
        if(list.length() == 1){
            return cosh(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function exp
      */
    this->registerFunction("exp", [](QList<double> list) -> double{
        if(list.length() == 1){
            qDebug() << "Try to calculate exp " << list[0];
            return exp(list[0]);
        }else{
            qDebug() << "ERROR: " << list.length();
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function e
      */
    this->registerFunction("e", [](QList<double> list) -> double{
        if(list.length() == 1){
            return exp(1);
        }else{
            throw "require 0 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function floor
      */
    this->registerFunction("floor", [](QList<double> list) -> double{
        if(list.length() == 1){
            return floor(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function ln
      */
    this->registerFunction("ln", [](QList<double> list) -> double{
        if(list.length() == 1){
            return log(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function lg
      */
    this->registerFunction("lg", [](QList<double> list) -> double{
        if(list.length() == 1){
            return log10(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function pi
      */
    this->registerFunction("pi", [](QList<double> list) -> double{
        if(list.length() == 1){
            return M_PI;
        }else{
            throw "require 0 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function sin
      */
    this->registerFunction("sin", [](QList<double> list) -> double{
        if(list.length() == 1){
            return sin(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function sqrt
      */
    this->registerFunction("sinh", [](QList<double> list) -> double{
        if(list.length() == 1){
            return sinh(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function tan
      */
    this->registerFunction("tan", [](QList<double> list) -> double{
        if(list.length() == 1){
            return tan(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function tanh
      */
    this->registerFunction("tanh", [](QList<double> list) -> double{
        if(list.length() == 1){
            return tanh(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function sqrt
      */
    this->registerFunction("sqrt", [](QList<double> list) -> double{
        if(list.length() == 1){
            return sqrt(list[0]);
        }else{
            throw "require 1 parameter, but provide " + QString("%0").arg(list.length());
        }
    });
    /**
      * Register function pow
      */
    this->registerFunction("pow", [](QList<double> list) -> double{
       if(list.length() == 2){
           return pow(list[0], list[1]);
       }else{
           throw "require 2 parameter, but provide " + QString("%0").arg(list.length());
       }
    });
}

/**
 * @brief Evaluator::registerFunction
 * @param functionName
 * @param dealer
 * @return
 */
bool Evaluator::registerFunction(QString functionName, std::function<double (QList<double>)> dealer){
    if(!this->re_function.contains(functionName)){
        this->re_function.insert(functionName, dealer);
        this->functionList.append(functionName);
        return true;
    }
    return false;
}

/**
 * @brief Evaluator::eval
 * @param expr
 * @return
 */
double Evaluator::eval(QString expr){
    if(this->isNumber(expr)){
        return expr.toDouble();
    }else{
        expr = this->stripSpace(expr);
        expr = this->evalFunction(expr);
        expr = this->evalParentheses(expr);
        expr = this->evalMul(expr);
        expr = this->evalPlus(expr);
        return eval(expr);
    }
}

/**
 * @brief Evaluator::isNumber
 * @param expr
 * @return if the string is only a number
 */
bool Evaluator::isNumber(const QString &expr){
    if((expr[0] != '-' && expr[0] != '+') && (expr[0] < '0' && expr[9] > '9')){
        return false;
    }
    for(auto i = 1; i < expr.length(); i++){
        if(!((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.')){
            return false;
        }
    }
    return true;
}

/**
 * @brief Evaluator::FindMatchedIndex
 * @param expr
 * @param leftParenthesesIndex
 * @return the right parentheses index
 */
int Evaluator::FindMatchedIndex(const QString &expr, const int &leftParenthesesIndex){
    int ans = 1;
    for(int i = leftParenthesesIndex + 1; i < expr.length(); i++){
        if(expr[i] == '(')
            ans++;
        else if(expr[i] == ')')
            ans--;
        if(!ans)
            return i;
    }
    return -1;
}

/**
 * @brief Evaluator::stripSpace
 * @param expr
 * @return a expr withou any space
 */
QString Evaluator::stripSpace(QString expr){
    QString re = "";
    for(auto &ch: expr){
        if(ch == ' ' || ch == '\t' || ch == '\n'){
            continue;
        }else{
            re += ch;
        }
    }
    return re;
}

/**
 * @brief Evaluator::evalFunction
 * @param expr
 * @return expr without function
 */
QString Evaluator::evalFunction(QString expr){
    if(this->isNumber(expr))
        return expr;
    for(auto &item : this->functionList){   // analyse all registered function
        while(expr.indexOf(item) != -1){    // found that the expr use the function `item`
            int start = expr.indexOf(item); // get the function start index
            int ans = -1;
            if(expr.length() > start + item.length()){  // find the function left parentheses
                if(expr[start + item.length()] == '(')
                    ans = 1;
                else
                    throw QString("Illegal expression, it should be '(' after %0").arg(expr.left(start + item.length()));
            }
            int end = this->FindMatchedIndex(expr, start + item.length() + 1);
            if(end != -1){  // could match
                QString str_args = expr.mid(start + item.length() + 1, end - start - item.length() - 1);    // get the function's args
                QStringList args;
                QString t = "";
                int count = 0;
                for(auto &ch:str_args){ // splite the function's args
                    if(ch == '(')
                        count++;
                    else if(ch == ')'){
                        count--;
                    }
                    if(ch == ',' && count == 0){
                        args.append(t);
                        t = "";
                    }else{
                        t += ch;
                    }
                }
                args.append(t);
                QList<double> params;
                for(auto &arg : args){
                    params.append(eval(arg));   // eval function's args to number and replace the function as it's value
                }
                expr = expr.left(start) + QString("%0").arg(this->re_function[item](params)) + expr.mid(end + 1);
            }else{
                throw "Unmatched Parentheses.";
            }
        }
    }
    return expr;
}

/**
 * @brief Evaluator::evalParentheses
 * @param expr
 * @return expr without parentheses
 */
QString Evaluator::evalParentheses(QString expr){
    if(this->isNumber(expr))
        return expr;
    int index = expr.indexOf('(');
    if(index == -1){
        return expr;
    }else{
        QString r_expr = expr.left(index);
        int end = this->FindMatchedIndex(expr, index + 1);
        if(end != -1){
            return expr.left(index) + QString("%0").arg(eval(expr.mid(index + 1, end - index - 1))) + this->evalParentheses(expr.right(expr.length() - end - 1));
        }
    }
}

/**
 * @brief Evaluator::FindForward
 * @param expr
 * @param s_index
 * @return the number first index before operator
 */
int Evaluator::FindForward(const QString &expr, const int &s_index){
    for(int i = s_index - 1; i >= 0; i--){
        if(expr[i] == '-' || expr[i] == '+'){
            return i;
        }
        if(!((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.')){
            return i+1;
        }
        if(i == 0){
            return 0;
        }
    }
    return -1;
}

/**
 * @brief Evaluator::FindAfter
 * @param expr
 * @param s_index
 * @return the number first index after operator
 */
int Evaluator::FindAfter(const QString &expr, const int &s_index){
    for(int i = s_index + 1; i < expr.length(); i++){
        if(i == s_index+1 && (expr[i] == '-' || expr[i] == '+')){
            continue;
        }
        if(!((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.')){
            return i-1;
        }
        if(i == expr.length() - 1){
            return expr.length() - 1;
        }
    }
}

void Evaluator::GetNumberAndIndex(const QString &expr, QString &number1, QString &number2, int &index_for, int &index_af, const int& op_index){
    number1 = "", number2 = "";
    index_for = this->FindForward(expr, op_index);
    index_af = this->FindAfter(expr, op_index);
    if(index_for != -1 && index_af != -1){
        number1 = expr.mid(index_for, op_index - index_for);
        number2 = expr.mid(op_index + 1, index_af - op_index);
    }
}

/**
 * @brief Evaluator::evalMul
 * @param expr
 * @return expr without * / %
 * should deal ^(pow) first
 */
QString Evaluator::evalMul(QString expr){
    if(this->isNumber(expr)){
        return expr;
    }
    int div_index = expr.indexOf('/') == -1 ? 0x7ffffff:expr.indexOf('/');
    int mul_index = expr.indexOf('*') == -1 ? 0x7ffffff:expr.indexOf('*');
    int mod_index = expr.indexOf('%') == -1 ? 0x7ffffff:expr.indexOf('%');
    if(div_index != 0x7ffffff && div_index < mul_index && div_index < mod_index){
        QString number1 = "", number2 = "";
        int index_for, index_af;
        this->GetNumberAndIndex(expr, number1, number2, index_for, index_af, div_index);
        QString r_expr = expr.left(index_for) + QString("%0").arg(number1.toDouble()/number2.toDouble()) + expr.mid(index_af + 1);
        return this->evalMul(r_expr);
    }
    if(mul_index != 0x7ffffff && mul_index < div_index && mul_index < mod_index){
        QString number1 = "", number2 = "";
        int index_for, index_af;
        this->GetNumberAndIndex(expr, number1, number2, index_for, index_af, mul_index);
        QString r_expr = expr.left(index_for) + QString("%0").arg(number1.toDouble()*number2.toDouble()) + expr.mid(index_af + 1);
        return this->evalMul(r_expr);
    }
    if(mod_index != 0x7ffffff && mod_index < div_index && mod_index < mul_index){
        QString number1 = "", number2 = "";
        int index_for, index_af;
        this->GetNumberAndIndex(expr, number1, number2, index_for, index_af, mod_index);
        QString r_expr = expr.left(index_for) + QString("%0").arg(number1.toInt()%number2.toInt()) + expr.mid(index_af + 1);
        return this->evalMul(r_expr);
    }
    return expr;
}

/**
 * @brief Evaluator::evalPlus
 * @param expr
 * @return the expr's result
 */
QString Evaluator::evalPlus(QString expr){
    if(this->isNumber(expr))
        return expr;
    int plus_index = expr.indexOf('+') == -1 ? 0x7ffffff:expr.indexOf('+');
    int dec_index = expr.indexOf('-') == -1 ? 0x7ffffff:expr.indexOf('-');
    QString number1 = "", number2 = "";
    int index_for, index_af;
    if(plus_index != 0x7ffffff  /*&& plus_index < dec_index */){
        this->GetNumberAndIndex(expr, number1, number2, index_for, index_af, plus_index);
        QString r_expr = expr.left(index_for) + QString("%0").arg(number1.toDouble() + number2.toDouble()) + expr.mid(index_af + 1);
        return this->evalPlus(r_expr);
    }
    if(dec_index != 0x7ffffff /*&& dec_index < plus_index*/){
        this->GetNumberAndIndex(expr, number1, number2, index_for, index_af, dec_index);
        QString r_expr = expr.left(index_for) + QString("%0").arg(number1.toDouble() - number2.toDouble()) + expr.mid(index_af + 1);
        return this->evalPlus(r_expr);
    }
    return expr;
}
