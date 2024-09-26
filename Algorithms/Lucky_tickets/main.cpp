#include <memory>
#include "Test.hpp"

int main(int argc, char** argv) {
  std::unique_ptr<Test::LuckyTicketsTest> luckyTicketsTest = std::make_unique<Test::LuckyTicketsTest>();
  luckyTicketsTest->Run();

  std::cin.get();
  return EXIT_SUCCESS;
}
