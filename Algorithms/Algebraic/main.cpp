#include <iostream>
#include "Fibonacci.hpp"

int main(int argc, char** argv) {
  std::cout << "Recursive: " << Algorithms::FibonacciRecursive(5) << std::endl;
  std::cout << "Iterative: " << Algorithms::FibonacciIterative(5) << std::endl;
  std::cout << "Gold: " << Algorithms::FibonacciGold(5) << std::endl;

  return EXIT_SUCCESS;
}
