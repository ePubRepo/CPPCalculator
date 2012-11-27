//
//  Calculator.cpp
//  Calculator
//
//

#include "Calculator.h"
#include "catch.hpp"

double Calculator::add(double opOne, double opTwo)
{
    return opOne + opTwo;
}

double Calculator::subtract(double opOne, double opTwo)
{
    return opOne - opTwo;
}

double Calculator::multiply(double opOne, double opTwo)
{
    return opOne * opTwo;
}

double Calculator::divide(double opOne, double opTwo)
{
    return opOne/opTwo;
}

// CATCH FRAMEWORK UNIT TESTS
TEST_CASE( "Calculator/add", "" ) {
    REQUIRE( Calculator::add(0, 1) == 1 );
    REQUIRE( Calculator::add(1, -1) == 0 );
    REQUIRE_FALSE( Calculator::add(2, 1) == 2 );
    REQUIRE_FALSE( Calculator::add(3, -3) == 6 );
}

TEST_CASE( "Calculator/subtract", "" ) {
    REQUIRE( Calculator::subtract(0, 1) == -1 );
    REQUIRE( Calculator::subtract(1, -1) == 2 );
    REQUIRE_FALSE( Calculator::subtract(2, 1) == 2 );
    REQUIRE_FALSE( Calculator::subtract(3, -3) == 7 );
}

TEST_CASE( "Calculator/multiply", "" ) {
    REQUIRE( Calculator::multiply(0, 1) == 0 );
    REQUIRE( Calculator::multiply(1, -1) == -1 );
    REQUIRE_FALSE( Calculator::multiply(2, 1) == 3 );
    REQUIRE_FALSE( Calculator::multiply(3, -3) == 20 );
}

TEST_CASE( "Calculator/divide", "" ) {
    REQUIRE( Calculator::divide(0, 1) == 0 );
    REQUIRE( Calculator::divide(1, -1) == -1 );
    REQUIRE( Calculator::divide(10, 2) == 5);
    REQUIRE( Calculator::divide(10, -4) == -2.5 );
    REQUIRE_FALSE( Calculator::divide(2, 1) == 3 );
    REQUIRE_FALSE( Calculator::divide(3, -3) == 20 );
}