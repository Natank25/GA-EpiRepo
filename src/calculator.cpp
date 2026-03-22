#include "calculator.hpp"

#include <stdexcept>

namespace calculator {
int add(int left, int right)
{
    return left + right;
}

int multiply(int left, int right)
{
    return left * right;
}

int divide(int left, int right)
{
    if (right == 0) {
        throw std::invalid_argument("division by zero");
    }
    return left / right;
}
}

