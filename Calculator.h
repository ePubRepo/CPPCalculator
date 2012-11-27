//
//  Calculator.h
//  Calculator
//
//

#ifndef __Calculator__Calculator__
#define __Calculator__Calculator__

#include <iostream>

class Calculator
{
public:
    static double add(double opOne, double opTwo);

    static double subtract(double opOne, double opTwo);

    static double multiply(double opOne, double opTwo);

    static double divide(double opOne, double opTwo);
};

#endif /* defined(__Calculator__Calculator__) */