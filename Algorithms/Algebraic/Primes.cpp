#include "Primes.hpp"

namespace Algorithms {
  int32_t Primes::countPrimes(int32_t value) {
    int32_t count{0};
    for (int32_t i = 2; i <= value; ++i)
      if (isPrime(i))
        ++count;
    return count;
  }

  bool Primes::isPrime(int32_t value) {
    if (value <= 2) return true;
    if (value % 2 == 0) return false;
    int32_t sqrt_res = static_cast<int32_t>(std::sqrt(value));
    for (int32_t i = 3; i <= sqrt_res; i += 2)
      if (value % i == 0)
        return false;
    return true;
  }

  int32_t Primes::Eratosphene(int32_t value) {
    std::vector<bool> divs;
    divs.resize(value + 1);
    int32_t count{};
    int32_t sqrt_res = static_cast<int32_t>(std::sqrt(value));
    for (int32_t p = 2; p <= value; ++p) {
      if (!divs[p]) {
        ++count;
        if (p <= sqrt_res)
          for (int32_t j = p * p; j <= value; j += p)
            divs[j] = true;
      }
    }
    return count;
  }
}
