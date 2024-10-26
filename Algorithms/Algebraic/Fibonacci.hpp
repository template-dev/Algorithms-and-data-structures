#ifndef F8DB5878_8B45_4651_95E5_D14234517F0D
#define F8DB5878_8B45_4651_95E5_D14234517F0D

#include <cmath>
#include <vector>
#include <chrono>
#include <iostream>

namespace Algorithms {
  class Fibonacci {
  public:
    void RunRecursive(int n);
    void RunIterative(int n);
    void RunGold(int n);
    void RunMatrix(int n);

    void RunAll(int n);

    uint64_t Recursive(int n);
    uint64_t Iterative(int n);
    uint64_t Gold(int n);
    uint64_t Matrix(int n);

  private:
    std::vector<std::vector<uint64_t>> m_matrixMult(const std::vector<std::vector<uint64_t>>& a, const std::vector<std::vector<uint64_t>>& b);
    std::vector<std::vector<uint64_t>> m_matrixPow(const std::vector<std::vector<uint64_t>>& a, int n);
  };
}

#endif /* F8DB5878_8B45_4651_95E5_D14234517F0D */
