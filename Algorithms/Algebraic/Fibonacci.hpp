#ifndef F8DB5878_8B45_4651_95E5_D14234517F0D
#define F8DB5878_8B45_4651_95E5_D14234517F0D

#include <cmath>
#include <vector>

namespace Algorithms {
  class Fibonacci {
  public:
    uint64_t Recursive(int n);
    uint64_t Iterative(int n);
    uint64_t Gold(int n);
  };

  /*std::vector<std::vector<uint64_t>> FibonacciMatrix(const std::vector<std::vector<uint64_t>>& a, const std::vector<std::vector<uint64_t>>& b) {
    if(a[1].size() != b[0].size()) return {};
    std::vector<std::vector<uint64_t>> result();
    return {};
  }*/
}

#endif /* F8DB5878_8B45_4651_95E5_D14234517F0D */
