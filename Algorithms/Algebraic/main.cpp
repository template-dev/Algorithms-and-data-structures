#include <memory>
#include "Fibonacci.hpp"

int main(int argc, char** argv) {
  std::unique_ptr<Algorithms::Fibonacci> pFibonacci = std::make_unique<Algorithms::Fibonacci>();
  pFibonacci->RunAll(100);

  return EXIT_SUCCESS;
}
