#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "Solution.hpp"

namespace Test {
  class LuckyTicketsTest {
  public:
    LuckyTicketsTest()
      : m_path{ std::filesystem::current_path() }
      , m_luckySolution{ std::make_unique<Solution::LuckyTikets>() }
    {}
    void Run();

  private:
    long m_readFile(const std::filesystem::path& filename);

  private:
    std::filesystem::path m_path;
    std::unique_ptr<Solution::LuckyTikets> m_luckySolution;
  };
}

#endif // TEST_HPP
