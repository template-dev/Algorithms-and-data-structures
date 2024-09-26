#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

namespace Test {
  class LuckyTicketsTest {
  public:
    LuckyTicketsTest(long resultFromSolution)
      : m_path{ std::filesystem::current_path() }
      , m_resultFromSolution{ resultFromSolution }
    {}
    void Run();

  private:
    long m_readFile(const std::filesystem::path& filename);

  private:
    std::filesystem::path m_path;
    long m_resultFromSolution;
  };
}

#endif // TEST_HPP
