#include <iostream>
#include "BitArithmetic.hpp"

int main() {
  std::cout << BitArithmetic::bit_count_first(0xF) << std::endl;
  std::cout << BitArithmetic::bit_count_second(0xF) << std::endl;
  std::cout << BitArithmetic::bit_count_cache_v1(0xF) << std::endl;

  return EXIT_SUCCESS;
}
