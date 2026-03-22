#include <criterion/criterion.h>

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

