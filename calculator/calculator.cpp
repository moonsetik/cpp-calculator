#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

using Number = double;

bool ReadNumber(Number& result) {
    std::cin >> result;
    if (!std::cin.fail()) {
        return true;
    }
    else {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

bool RunCalculatorCycle() {
    Number result;
    Number add_num;
    Number memmory;
    std::string operation;
    bool was_error = false;
    bool memmory_empty = true;
    was_error = ReadNumber(result);
    if (!was_error) {
        return 0;
    }
    else {
        std::cin >> operation;
        while (operation != "q") {
            if (operation == "=") {
                std::cout << result << std::endl;
            }
            else if (operation == "+") {
                was_error = ReadNumber(add_num);
                if (!was_error) {
                    break;
                }
                result += add_num;
            }
            else if (operation == "-") {
                was_error = ReadNumber(add_num);
                if (!was_error) {
                    break;
                }
                result -= add_num;
            }
            else if (operation == "*") {
                was_error = ReadNumber(add_num);
                if (!was_error) {
                    break;
                }
                result *= add_num;
            }
            else if (operation == "/") {
                was_error = ReadNumber(add_num);
                if (!was_error) {
                    break;
                }
                result /= add_num;
            }
            else if (operation == "**") {
                was_error = ReadNumber(add_num);
                if (!was_error) {
                    break;
                }
                result = pow(result, add_num);
            }
            else if (operation == ":") {
                was_error = ReadNumber(add_num);
                if (!was_error) {
                    break;
                }
                result = add_num;
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