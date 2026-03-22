cmake_minimum_required(VERSION 3.16)

project(ga_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_ASAN "Enable AddressSanitizer" OFF)

if(ENABLE_ASAN)
	add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
	add_link_options(-fsanitize=address)
endif()

add_library(calculator src/calculator.cpp)
target_include_directories(calculator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(calculator PRIVATE -Wall -Wextra -Werror)

add_executable(ga_app src/main.cpp)
target_link_libraries(ga_app PRIVATE calculator)
target_compile_options(ga_app PRIVATE -Wall -Wextra -Werror)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CRITERION REQUIRED IMPORTED_TARGET criterion)

add_executable(unit_tests EXCLUDE_FROM_ALL tests/test_calculator.cpp)
target_link_libraries(unit_tests PRIVATE calculator PkgConfig::CRITERION)
target_compile_options(unit_tests PRIVATE -Wall -Wextra -Werror)

enable_testing()
add_test(NAME unit_tests COMMAND unit_tests)
