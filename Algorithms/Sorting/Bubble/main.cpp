#include <iostream>
#include "Bubble.hpp"

int main() {
  std::vector<int32_t> buffer {1, 7, 5, 9, 3, 4};
  Sort::Bubble(buffer);

  for(const auto& i : buffer)
    std::cout << i << " ";
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
