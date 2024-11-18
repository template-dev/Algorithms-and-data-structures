#include "Power.hpp"

namespace Algorithms {
  long double Power::PowerRecursion(long double value, int n) {
    if (n == 0) return 1.0;
    if (n == 1) return value;
    if (n < 0) return 1.0 / PowerRecursion(value, -n);
    return PowerRecursion(value, n - 1) * value;
  }

  long double Power::PowerIterative(long double value, int n) {
    if (n == 0) return 1.0;
    if (n == 1) return value;
    if (n < 0) {
      value = 1 / value;
      n = -n;
    }
    long double r = 1.0;
    for (int i = 0; i < n; ++i)
      r *= value;
    return r;
  }

  long double Power::PowerOptimized(long double value, int n) {
    if (n == 0) return 1.0;
    if (n == 1) return value;
    if (n < 0) {
      value = 1 / value;
      n = -n;
    }
    if (n % 2 == 0) {
      long double r = 1.0;
      for (int i = 0; i < n / 2; ++i)
        r *= value;
      return r * r;
    }
    else {
      long double r = 1;
      for (int i = 0; i < n / 2; ++i)
        r *= value;
      return r * r * value;
    }
  }
}
