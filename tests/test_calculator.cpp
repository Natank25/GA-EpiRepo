#include <criterion/criterion.h>

#include <stdexcept>

#include "calculator.hpp"

Test(calculator_addition, adds_positive_numbers)
{
    cr_assert_eq(calculator::add(2, 3), 5);
}

Test(calculator_addition, adds_negative_numbers)
{
    cr_assert_eq(calculator::add(-4, -6), -10);
}

Test(calculator_addition, adds_mixed_sign_numbers)
{
    cr_assert_eq(calculator::add(-4, 6), 2);
}

Test(calculator_multiplication, multiplies_positive_numbers)
{
    cr_assert_eq(calculator::multiply(3, 4), 12);
}

Test(calculator_division, divides_even_numbers)
{
    cr_assert_eq(calculator::divide(20, 5), 4);
}

Test(calculator_division, throws_on_divide_by_zero)
{
    bool did_throw = false;
    try {
        (void)calculator::divide(10, 0);
    } catch (const std::invalid_argument&) {
        did_throw = true;
    }
    cr_assert(did_throw);
}

