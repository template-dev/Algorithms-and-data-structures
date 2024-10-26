#include <iostream>
#include "GCD.hpp"

int main(int argc, char** argv) {
  Algorithms::GCD gcd;
  std::cout << "Recursive " << gcd.SteinzRecursive(125, 50) << std::endl;

  return EXIT_SUCCESS;
}
