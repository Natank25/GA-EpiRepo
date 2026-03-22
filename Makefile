CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -Iinclude
CRITERION_CFLAGS := $(shell pkg-config --cflags criterion)
CRITERION_LIBS := $(shell pkg-config --libs criterion)

SRC_DIR := src
TEST_DIR := tests

CALCULATOR_OBJ := calculator.o

.PHONY: all tests_runner run_tests clean fclean re

all: ga_app

ga_app: main.o $(CALCULATOR_OBJ)
	$(CXX) main.o $(CALCULATOR_OBJ) -o $@

tests_runner: test_calculator.o $(CALCULATOR_OBJ)
	$(CXX) test_calculator.o $(CALCULATOR_OBJ) $(CRITERION_LIBS) -o $@

run_tests: tests_runner
	./tests_runner

main.o: $(SRC_DIR)/main.cpp include/calculator.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CALCULATOR_OBJ): $(SRC_DIR)/calculator.cpp include/calculator.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test_calculator.o: $(TEST_DIR)/test_calculator.cpp include/calculator.hpp
	$(CXX) $(CXXFLAGS) $(CRITERION_CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f ga_app tests_runner

re: fclean all

