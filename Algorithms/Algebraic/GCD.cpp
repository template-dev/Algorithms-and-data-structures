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

  int64_t GCD::SteinzRecursive(int64_t m, int64_t n) {
    if (m == 0 || n == 0) return 1;
    if (m == n) return m;

    if (((m % 2) == 0) && ((n % 2) == 0))
      return 2 * SteinzRecursive(m / 2, n / 2);

    if (((m % 2) == 0) &&  ((m % 2) == 1))
      return SteinzRecursive(m / 2, n);

    if (((m % 2) == 1) && ((n % 2) == 0))
      return SteinzRecursive(m, n / 2);

    if (((m % 2) == 1) && ((n % 2) == 1)) {
      if (m > n)
        return SteinzRecursive(n, (m - n)/2);
      else
        return SteinzRecursive(m, (n - m)/2);
    }
    return 1;
  }

  int64_t GCD::SteinzIterative(int64_t m, int64_t n) {
    if (m == 0 || n == 0) return 1;
    if (m == n) return m;

    if (((m % 2) == 0) && ((n % 2) == 0)) {

    }
    return {};
  }
}
