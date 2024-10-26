#include <iostream>
#include "GCD.hpp"

int main(int argc, char** argv) {
  Algorithms::GCD gcd;
  std::cout << "Recursive " << gcd.EuclidSubtractionRecursive(125, 50) << std::endl;
  std::cout << "Iterative " << gcd.EuclidSubtractionIterative(125, 50) << std::endl;

  std::cout << "Recursive " << gcd.EuclidRemainderOfTheDivisionRecursive(125, 50) << std::endl;
  std::cout << "Iterative " << gcd.EuclidRemainderOfTheDivisionIterative(125, 50) << std::endl;

  return EXIT_SUCCESS;
}
