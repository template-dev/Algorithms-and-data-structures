#ifndef F8DB5878_8B45_4651_95E5_D14234517F0D
#define F8DB5878_8B45_4651_95E5_D14234517F0D

#include <cmath>

namespace Algorithms {
  uint64_t FibonacciRecursive(int n) {
    if (n == 1 || n == 2) return 1;
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
  }

  uint64_t FibonacciIterative(int n) {
    uint64_t f1 = 1;
    uint64_t f2 = 1;
    for(int i = 2; i < n; ++i) {
      uint64_t f3 = f1 + f2;
      f1 = f2;
      f2 = f3;
    }
    return f2;
  }

  uint64_t FibonacciGold(int n) {
    double fi = (1.0 + std::sqrt(5)) / 2.0;
    return static_cast<uint64_t>(std::floor(std::pow(fi, n) / std::sqrt(5) + 1.0 / 2.0));
  }
}

#endif /* F8DB5878_8B45_4651_95E5_D14234517F0D */
