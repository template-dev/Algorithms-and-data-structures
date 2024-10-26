#include <iostream>
#include "Fibonacci.hpp"

int main(int argc, char** argv) {
  Algorithms::Fibonacci fib;
  std::cout << "Recursive: " << fib.Recursive(5) << std::endl;
  std::cout << "Iterative: " << fib.Iterative(5) << std::endl;
  std::cout << "Gold: " << fib.Gold(5) << std::endl;
  std::cout << "Matrix: " << fib.Matrix(5) << std::endl;

  return EXIT_SUCCESS;
}
