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
      virtual ~Bitboard() = default;
      void print(uint64_t row = 0);

    protected:
      virtual void Steps() = 0;
      uint64_t getBitboard() const { return m_bitboard; }
      void setBitboard(uint64_t newBitboard);

    private:
      uint64_t m_bitboard;
    };
}

namespace BitArithmetic {
  class King : public Bitboard {
  public:
    King(uint64_t mask);
    King(const std::string& str);
    void Steps() override;
  };
}

#endif /* CB20B50C_752C_4E24_8D5E_6CA8068EC132 */
