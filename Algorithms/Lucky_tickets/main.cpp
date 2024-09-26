#include <memory>
#include "Solution.hpp"
#include "Test.hpp"

int main(int argc, char** argv) {
  std::unique_ptr<Solution::LuckyTikets> luckyTickets = std::make_unique<Solution::LuckyTikets>();
  std::unique_ptr<Test::LuckyTicketsTest> luckyTicketsTest = std::make_unique<Test::LuckyTicketsTest>(luckyTickets->Run());
  luckyTicketsTest->Run();
  std::cout << luckyTickets->Run() << std::endl;

  std::cin.get();
  return EXIT_SUCCESS;
}
