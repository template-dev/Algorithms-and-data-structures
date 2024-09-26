#include "Solution.hpp"

int main(int argc, char** argv) {
  try {
    Solution::LuckyTikets luckyTickets;
    std::cout << luckyTickets.Run() << std::endl;
  }
  catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  std::cin.get();
  return EXIT_SUCCESS;
}
