#include "GCD.hpp"

namespace Algorithms {
  int64_t GCD::EuclidSubtractionRecursive(int64_t m, int64_t n) {
    if (m == 0 || n == 0) return 1;
    if (m == n) return m;
    if (m > n) return EuclidSubtractionRecursive(m - n, n);
    else return EuclidSubtractionRecursive(n - m, m);
  }

  int64_t GCD::EuclidSubtractionIterative(int64_t m, int64_t n) {
    if (m == 0 || n == 0) return 1;
    if (m == n) return m;
    while (m != n) {
      if (m > n) m -= n;
      else n -= m;
    }
    return m;
  }

  int64_t GCD::EuclidRemainderOfTheDivisionRecursive(int64_t m, int64_t n) {
    if (m == 0 || n == 0) return 1;
    if (m == n) return m;
    if (m > n) return EuclidSubtractionRecursive(m % n, n);
    else return EuclidSubtractionRecursive(n % m, m);
  }

  int64_t GCD::EuclidRemainderOfTheDivisionIterative(int64_t m, int64_t n) {
    if (m == 0 || n == 0) return 1;
    if (m == n) return m;
    while (n != 0) {
        int64_t temp = n;
        n = m % n;
        m = temp;
    }
    return m;
  }
}
