# Simple C++ + Criterion Example

This repository contains:
- `ga_app`: a small C++ program that adds two integers.
- `tests_runner`: unit tests written with Criterion.

## Project Layout

- `include/calculator.hpp`: function declaration.
- `src/calculator.cpp`: function implementation.
- `src/main.cpp`: application entry point.
- `tests/test_calculator.cpp`: Criterion unit tests.
- `Makefile`: build configuration.

## Prerequisites

- A C++17 compiler (`g++` or `clang++`)
- Criterion development package with `pkg-config` metadata

On Debian/Ubuntu, Criterion is usually available via:

```bash
sudo apt-get update
sudo apt-get install -y make g++ pkg-config libcriterion-dev
```

## Build

```bash
make all
```

## Run the Program

```bash
./ga_app
```

## Build and Run Tests

```bash
make run_tests
```
