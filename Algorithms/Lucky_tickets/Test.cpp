#include "Test.hpp"
#include <chrono>

void Test::LuckyTicketsTest::Run() {
  short iter{};
  int counter{1};
  while (true) {
    auto inputFile = m_path / "TestData" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "TestData" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile))
      return;

    int64_t inputValue = m_readFile(inputFile);
    int64_t outputValue = m_readFile(outputFile);

    auto begin = std::chrono::steady_clock::now();

    int64_t solveResult = m_luckySolution->Run(inputValue);

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    if (solveResult == outputValue)
      std::cout << "Test " << iter << " OK: " << inputValue;
    else
      std::cout << "Test " << iter << " ERROR: " << inputValue << " expected: " << outputValue;

    std::cout << " | The time: " << elapsed_ms.count() << " ms" << std::endl;

    ++iter;
    ++counter;
  }
}

int64_t Test::LuckyTicketsTest::m_readFile(const std::filesystem::path& filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    int64_t number{};
    file >> number;
    file.close();
    return number;
  }
  else {
    std::cerr << "The file couldn't be opened!" << std::endl;
    return -1;
  }
}
