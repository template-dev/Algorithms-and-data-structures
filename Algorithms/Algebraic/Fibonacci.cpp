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

  uint64_t Fibonacci::Matrix(int n) {
    std::vector<std::vector<uint64_t>> init {
      {1, 1},
      {1, 0}
    };
    return m_matrixPow(init, n - 1)[0][0];
  }

  std::vector<std::vector<uint64_t>> Fibonacci::m_matrixMult(const std::vector<std::vector<uint64_t>>& a, const std::vector<std::vector<uint64_t>>& b) {
    if(a[1].size() != b[0].size()) return {};
    std::vector<std::vector<uint64_t>> result(a[0].size(), std::vector<uint64_t>(b[1].size()));
    for(int i = 0; i < a[0].size(); ++i) {
      for(int j = 0; j < b[1].size(); ++j) {
        uint64_t c{};
        for(int k = 0; k < a[1].size(); ++k) {
          c += a[i][k] * b[k][j];
        }
        result[i][j] = c;
      }
    }
    return result;
  }

  std::vector<std::vector<uint64_t>> Fibonacci::m_matrixPow(const std::vector<std::vector<uint64_t>>& a, int n) {
    if (n <= 1) return a;
    if ((n & 1) > 0) {
      std::vector<std::vector<uint64_t>> p = m_matrixPow(a, n / 2);
      p = m_matrixMult(p, p);
      return m_matrixMult(a, p);
    }
    std::vector<std::vector<uint64_t>> p = m_matrixPow(a, n / 2);
    return m_matrixMult(p, p);
  }
}
