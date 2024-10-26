#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "LuckyTikets.hpp"

namespace Test {
  class LuckyTicketsTest {
  public:
    LuckyTicketsTest()
      : m_path{ std::filesystem::current_path() }
      , m_luckySolution{ std::make_unique<Algorithms::LuckyTikets>() }
    {}
    void Run();

  private:
    int64_t m_readFile(const std::filesystem::path& filename);

  private:
    std::filesystem::path m_path;
    std::unique_ptr<Algorithms::LuckyTikets> m_luckySolution;
  };
}

#endif // TEST_HPP
