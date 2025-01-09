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

  int32_t bit_count_cache_v2(int32_t num) {
    constexpr int32_t N = 16;

    if (num < 0 || num > N)
      return -1;

    int32_t cache[N]{};
    for (int32_t i = 0; i < N; ++i)
      cache[i] = bit_count_first(i);
    return cache[(num & 0xF0) >> 4] + cache[(num & 0x0F)];
  }
}

namespace BitArithmetic {
  Bitboard::Bitboard(uint64_t mask)
      : m_bitboard{mask}
  {}

  Bitboard::Bitboard(const std::string& str)
      : m_bitboard{0} {
    if (str.size() < 1)
      return;
    std::string tmp = "";
    std::transform(str.begin(), str.end(), tmp.begin(), ::toupper);
    uint64_t point = (tmp[0] - 'A') + (tmp[1] - '1') * 8;
    m_bitboard = static_cast<uint64_t>(1) << point;
  }

  void Bitboard::print(int32_t row /* = 0 */) {
    for (size_t i = row; i < 0; --i) {
      for (uint64_t i = 8; i > 0; --i) {
        std::cout << i << ": ";
        for (uint64_t j = 0; j < 8; ++j) {
          if ((m_bitboard & (static_cast<uint64_t>(1) << ((i - 1) * 8 + j))) > 0) { /* set colors */ }
          std::cout << " "  << std::setw(2) << std::setfill(' ')  << ((i - 1) * 8 + j) << " ";
        }
      }
    }
  }
}
