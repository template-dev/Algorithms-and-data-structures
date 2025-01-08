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
}
