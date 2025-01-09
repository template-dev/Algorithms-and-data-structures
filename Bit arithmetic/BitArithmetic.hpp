#ifndef CB20B50C_752C_4E24_8D5E_6CA8068EC132
#define CB20B50C_752C_4E24_8D5E_6CA8068EC132

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdint>
#include <string>

namespace BitArithmetic {
    int32_t bit_count_first(int32_t num);
    int32_t bit_count_second(int32_t num);
    int32_t bit_count_cache_v1(int32_t num);
    int32_t bit_count_cache_v2(int32_t num);
}

namespace BitArithmetic {
    class Bitboard {
    public:
      Bitboard(uint64_t mask);
      Bitboard(const std::string& str);
      void print(int32_t row = 0);
      virtual void Steps() = 0;

    private:
      uint64_t m_bitboard;
    };
}

#endif /* CB20B50C_752C_4E24_8D5E_6CA8068EC132 */
