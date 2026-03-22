# Simple C++ + Criterion Example

This repository contains:
- `ga_app`: a small C++ program that adds two integers.
- `unit_tests`: unit tests written with Criterion.

## Project Layout

- `include/calculator.hpp`: function declaration.
- `src/calculator.cpp`: function implementation.
- `src/main.cpp`: application entry point.
- `tests/test_calculator.cpp`: Criterion unit tests.
- `CMakeLists.txt`: CMake build configuration.

## Prerequisites

- A C++17 compiler (`g++` or `clang++`)
- CMake (3.16+)
- Criterion development package with `pkg-config` metadata

On Debian/Ubuntu, Criterion is usually available via:

```bash
sudo apt-get update
sudo apt-get install -y cmake g++ pkg-config libcriterion-dev
```

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Build with AddressSanitizer

```bash
cmake -S . -B build-asan -DENABLE_ASAN=ON
cmake --build build-asan
```

## Run the Program

```bash
./build/ga_app
```

## Build and Run Tests

```bash
cmake --build build --target unit_tests
ctest --test-dir build --output-on-failure -R '^unit_tests$'
```
