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
    std::string tmp = str;
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
    uint64_t point = (tmp[0] - 'A') + (tmp[1] - '1') * 8;
    m_bitboard = static_cast<uint64_t>(1) << point;
  }

  void Bitboard::print(uint64_t row /* = 0 */) {
    for (int64_t i = static_cast<int64_t>(row); i >= 0; --i) {
      for (uint64_t inner = 8; inner > 0; --inner) {
        std::cout << inner << ": ";
        for (uint64_t j = 0; j < 8; ++j) {
          if ((m_bitboard & (static_cast<uint64_t>(1) << ((inner - 1) * 8 + j))) > 0) { /* set color */ }
          std::cout << " " << std::setw(2) << std::setfill(' ') << ((inner - 1) * 8 + j) << " ";
        }
        std::cout << '\n';
      }
    }
  }

  void Bitboard::setBitboard(uint64_t newBitboard) {
    if (newBitboard != m_bitboard)
      m_bitboard = newBitboard;
  }
}

namespace BitArithmetic {
  King::King(uint64_t mask)
      : Bitboard{mask}
  {}

  King::King(const std::string& str)
      : Bitboard{str}
  {}

  void King::Steps() {
    uint64_t mask = (getBitboard() & 0x7F7F7F7F7F7F7F7F) << 1;
    mask |= (getBitboard() & 0xFEFEFEFEFEFEFEFE) >> 1;
    mask |= (getBitboard() << 8);
    mask |= (getBitboard() >> 8);
    mask |= (getBitboard() & 0xFEFEFEFEFEFEFEFE) >> 9;
    mask |= (getBitboard() & 0xFEFEFEFEFEFEFEFE) << 7;
    mask |= (getBitboard() & 0x7F7F7F7F7F7F7F7F) << 9;
    mask |= (getBitboard() & 0x7F7F7F7F7F7F7F7F) >> 7;
    setBitboard(mask);
  }
}
