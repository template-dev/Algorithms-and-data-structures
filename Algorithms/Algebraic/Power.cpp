#include "Power.hpp"

namespace Algorithms {
  double Power::PowerRecursion(double value, int64_t n) {
    if (n == 0) return 1.0;
    if (n == 1) return value;
    if (n < 0) return 1.0 / PowerRecursion(value, -n);
    return PowerRecursion(value, n - 1) * value;
  }

  double Power::PowerIterative(double value, int64_t n) {
    if (n == 0) return 1.0;
    if (n == 1) return value;
    if (n < 0) {
      value = 1 / value;
      n = -n;
    }
    double r = 1.0;
    for (int i = 0; i < n; ++i)
      r *= value;
    return r;
  }

  double Power::PowerOptimized(double value, int64_t n) {
    if (n == 0) return 1.0;
    if (n == 1) return value;
    if (n < 0) {
      value = 1 / value;
      n = -n;
    }

    double r = 1.0;
    for (int i = 0; i < n / 2; ++i)
      r *= value;

    return (n % 2 == 0) ? r * r : r * r * value;
  }
}
