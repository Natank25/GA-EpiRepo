#pragma once

namespace calculator {
int add(int left, int right);
int multiply(int left, int right);

/**
 * Divides two integers.
 *
 * @throws std::invalid_argument if right is zero.
 */
int divide(int left, int right);
}

