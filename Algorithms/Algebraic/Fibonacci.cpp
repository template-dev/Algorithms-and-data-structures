#include "Fibonacci.hpp"

namespace Algorithms {
  uint64_t Fibonacci::Recursive(int n) {
    if (n == 1 || n == 2) return 1;
    return Recursive(n - 1) + Recursive(n - 2);
  }

  uint64_t Fibonacci::Iterative(int n) {
    uint64_t f1 = 1;
    uint64_t f2 = 1;
    for(int i = 2; i < n; ++i) {
      uint64_t f3 = f1 + f2;
      f1 = f2;
      f2 = f3;
    }
    return f2;
  }

  uint64_t Fibonacci::Gold(int n) {
    double fi = (1.0 + std::sqrt(5)) / 2.0;
    return static_cast<uint64_t>(std::floor(std::pow(fi, n) / std::sqrt(5) + 1.0 / 2.0));
  }
}
