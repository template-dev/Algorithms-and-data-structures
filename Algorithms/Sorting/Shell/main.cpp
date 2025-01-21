#include <iostream>
#include "ShellSort.hpp"

int main() {
  std::vector<int32_t> buffer {1, 7, 5, 9, 3, 4};
  Sort::Shell(buffer);

  for(const auto& i : buffer)
    std::cout << i << " ";
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
