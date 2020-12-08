#ifndef NUMERALCONVERTER_H
#define NUMERALCONVERTER_H

#include <string>
#include <cmath>

class NumeralConverter
{
public:
    NumeralConverter();

    enum NumSystem { BIN, OCT, DEC, HEX };

    NumeralConverter(NumSystem system, std::string value);
    bool valueGood();
    std::string ConvertValue(NumSystem target);

private:
    std::string inputValue;
    NumSystem valueSystem;

    int decodeDigit(char digit);

    std::string decToSys(int sys);
    std::string sysToDec(int sys);
};

#endif // NUMERALCONVERTER_H
