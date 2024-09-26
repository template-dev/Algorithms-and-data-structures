#include "Test.hpp"

void Test::LuckyTicketsTest::Run() {
  short iter{};
  auto inputFile = m_path / "TestData" / "test." += std::to_string(iter) + ".in";
  auto outputFile = m_path / "TestData" / "test." += std::to_string(iter) + ".out";
  std::cout << inputFile << std::endl << outputFile << std::endl;

  while (true) {
    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile))
      return;

    long inputValue = m_readFile(inputFile);
    long outputValue = m_readFile(outputFile);

    if (m_resultFromSolution == outputValue)
      std::cout << "Test " << iter << " OK: " << inputValue << std::endl;
    else
      std::cout << "Test " << iter << " ERROR: " << inputValue << " expected: " << outputValue << std::endl;

    ++iter;
  }
}

long Test::LuckyTicketsTest::m_readFile(const std::filesystem::path& filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    long number{};
    file >> number;
    file.close();
    return number;
  }
  else {
    std::cerr << "The file couldn't be opened!" << std::endl;
    return -1;
  }
}
