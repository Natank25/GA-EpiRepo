#include <iostream>

#include "calculator.hpp"

int main()
{
    const int result = calculator::add(2, 3);
    std::cout << "2 + 3 = " << result << '\n';
    return 0;
}

