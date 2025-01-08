#include "BitArithmetic.hpp"

namespace BitArithmetic {
  int32_t bit_count_first(int32_t num) {
    int32_t count = 0;
    int32_t mask = 0x01;
    while (mask > 0) {
      if ((num & mask) > 0)
        ++count;
      mask <<= 1;
    }
    return count;
  }

  int32_t bit_count_second(int32_t num) {
    int32_t count = 0;
    while(num > 0) {
      ++count;
      num &= (num - 1);
    }
    return count;
  }

  int32_t bit_count_cache_v1(int32_t num) {
    constexpr int32_t N = 256;

    if (num < 0 || num > N)
      return -1;

    int32_t cache[N]{};
    for (int32_t i = 0; i < N; ++i)
      cache[i] = bit_count_first(i);
    return cache[num];
  }
}
