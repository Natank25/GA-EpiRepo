#include <iostream>
#include <stdexcept>

#include "calculator.hpp"

int main()
{
    std::cout << "Calculator demo\n";
    std::cout << "---------------\n";

    const int sum = calculator::add(2, 3);
    const int product = calculator::multiply(4, 5);

    std::cout << "2 + 3  = " << sum << '\n';
    std::cout << "4 * 5  = " << product << '\n';

    try {
        const int quotient = calculator::divide(10, 2);
        std::cout << "10 / 2 = " << quotient << '\n';
        const int zero_division = calculator::divide(10, 0);
        std::cout << "10 / 0 = " << zero_division << '\n';
    } catch (const std::invalid_argument& error) {
        std::cout << "10 / 0 = error (" << error.what() << ")\n";
    }

    return 0;
}

