/*
 * File: Calculator.cpp
 * --------------------------
 * You can use this file as a starter for 
 * testing things out that aren't assignments.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "Calculator.h"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

using namespace std;

enum UserOperation {
    ADD = '+',
    SUBTRACT = '-',
    DIVIDE = '/',
    MULTIPLY = '*',
    EXIT = 'E'
};

struct Operands {
    int operand1;
    int operand2;
};

UserOperation getNextUserOperation()
{
    bool promptForNewOperation = true;
    UserOperation inputtedUserOperation;

    while (promptForNewOperation)
    {
        cout << "What Operation Do You Want to Perform?" << endl;
        cout << "Options include +, -, /, *, E to exit: ";

        char finalUserInput;
        string rawUserInput;
        cin >> rawUserInput;
        finalUserInput = rawUserInput[0];

        // assume the characted inputted was valid unless shown otherwise
        promptForNewOperation = false;
        switch (finalUserInput)
        {
            case ADD:
                inputtedUserOperation = ADD;
                break;
            case SUBTRACT:
                inputtedUserOperation = SUBTRACT;
                break;
            case DIVIDE:
                inputtedUserOperation = DIVIDE;
                break;
            case MULTIPLY:
                inputtedUserOperation = MULTIPLY;
                break;
            case EXIT:
                inputtedUserOperation = EXIT;
                break;
            default:
                promptForNewOperation = true;
                cout << "Please enter a valid operation." << endl;
                break;
        }
    }
    return inputtedUserOperation;
}

int getNextOperand(string prompt)
{
    int operand;
    cout << prompt << ": ";
    cin >> operand;
    return operand;
}

Operands getUserOperands()
{
    Operands userOperands;
    userOperands.operand1 = getNextOperand("Please enter the FIRST operand");
    userOperands.operand2 = getNextOperand("Please enter the SECOND operand");
    return userOperands;
}

double performOperation(UserOperation operation, Operands userOperands)
{
    double result;
    switch (operation)
    {
        case ADD:
            result = Calculator::add(userOperands.operand1,
                                     userOperands.operand2);
            break;
        case SUBTRACT:
            result = Calculator::subtract(userOperands.operand1,
                                          userOperands.operand2);
            break;
        case DIVIDE:
            result = Calculator::divide(userOperands.operand1,
                               userOperands.operand2);
            break;
        case MULTIPLY:
            result = Calculator::multiply(userOperands.operand1,
                                 userOperands.operand2);
            break;
        default:
            break;
    }
    return result;
}

int runProgram()
{
    // Step 0: Define needed variables
    bool continueCalculator = true;

    // Step 1: Obtain user's desired operation and perform it
    Operands useOperands;
    UserOperation desiredOperation;
    double result;
    while (continueCalculator)
    {
        desiredOperation = getNextUserOperation();
        switch (desiredOperation)
        {
            case ADD:
            case SUBTRACT:
            case DIVIDE:
            case MULTIPLY:
                useOperands = getUserOperands();
                result = performOperation(desiredOperation, useOperands);
                cout << "Answer: " << result << endl << endl;
                break;
            case EXIT:
            default:
                continueCalculator = false;
                break;
        }
    }

    // Step 2: Exit the program
    return 0;
}

int main() {
    // CATCH UNIT TESTS
    // Create a default config object
    Catch::Config config;

    // Configure CATCH to run all tests starting with "mytests"
    config.addTestSpec( "Calculator/*" );

    // Forward on to CATCH's main using our custom config.
    // This overload doesn't take command line arguments
    // So the config object must be fully set up
    Catch::Main( config );

    // NORMAL CODE
    return runProgram();
}

// CATCH FRAMEWORK UNIT TESTS
TEST_CASE( "Calculator/performOperation", "" ) {
    Operands myOperands;
    myOperands.operand1 = 10;
    myOperands.operand2 = 20;
    REQUIRE( performOperation(ADD, myOperands) == 30 );
    REQUIRE_FALSE( performOperation(ADD, myOperands) == 20 );
    REQUIRE( performOperation(SUBTRACT, myOperands) == -10 );
    REQUIRE_FALSE( performOperation(SUBTRACT, myOperands) == 10 );
    REQUIRE( performOperation(DIVIDE, myOperands) == 0.5 );
    REQUIRE_FALSE( performOperation(DIVIDE, myOperands) == 2 );
    REQUIRE( performOperation(MULTIPLY, myOperands) == 200 );
    REQUIRE_FALSE( performOperation(MULTIPLY, myOperands) == 0 );
}