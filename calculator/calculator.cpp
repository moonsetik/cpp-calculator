#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>


bool ReadNumber(Number& result) {
    std::cin >> result;
    if (!std::cin.fail()) {
        return true;
    }
    std::cerr << "Error: Numeric operand expected" << std::endl;
    return false;
}

bool RunCalculatorCycle() {
    Number memmory;
    bool was_error = false;
    bool memmory_empty = true;
    Number result;
    was_error = ReadNumber(result);
    if (!was_error) {
        return 0;
    }
    else {
        std::string operation;
        std::cin >> operation;
        Number additional_number;
        while (operation != "q") {
            if (operation == "=") {
                std::cout << result << std::endl;
            }
            else if (operation == "+") {
                was_error = ReadNumber(additional_number);
                if (!was_error) {
                    break;
                }
                result += additional_number;
            }
            else if (operation == "-") {
                was_error = ReadNumber(additional_number);
                if (!was_error) {
                    break;
                }
                result -= additional_number;
            }
            else if (operation == "*") {
                was_error = ReadNumber(additional_number);
                if (!was_error) {
                    break;
                }
                result *= additional_number;
            }
            else if (operation == "/") {
                was_error = ReadNumber(additional_number);
                if (!was_error) {
                    break;
                }
                result /= additional_number;
            }
            else if (operation == "**") {
                was_error = ReadNumber(additional_number);
                if (!was_error) {
                    break;
                }
                result = pow(result, additional_number);
            }
            else if (operation == ":") {
                was_error = ReadNumber(additional_number);
                if (!was_error) {
                    break;
                }
                result = additional_number;
            }
            else if (operation == "c") {
                result = 0;
            }
            else if (operation == "s") {
                memmory = result;
                memmory_empty = false;
            }
            else if (operation == "l") {
                if (memmory_empty) {
                    std::cerr << "Error: Memory is empty" << std::endl;
                    break;
                }
                else {
                    result = memmory;
                }
            }
            else {
                std::cerr << "Error: Unknown token " << operation << std::endl;
                break;
            }
            std::cin >> operation;
        }
    }
    if (!was_error) {
        return true;
    }
    else {
        return false;
    }
}