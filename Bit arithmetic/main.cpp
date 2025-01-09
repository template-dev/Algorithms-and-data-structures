#include <iostream>
#include <memory>
#include "BitArithmetic.hpp"

int main() {
  std::cout << BitArithmetic::bit_count_first(0xF) << std::endl;
  std::cout << BitArithmetic::bit_count_second(0xF) << std::endl;
  std::cout << BitArithmetic::bit_count_cache_v1(0xF) << std::endl;
  std::cout << BitArithmetic::bit_count_cache_v2(0xF) << std::endl;
  try {
    std::string str = "";
    std::cin >> str;
    std::unique_ptr<BitArithmetic::Bitboard> king = std::make_unique<BitArithmetic::King>(str);
    king->print();
  }
  catch(const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
