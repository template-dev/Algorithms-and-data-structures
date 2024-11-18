#ifndef D25CB2E1_C813_4117_90A3_BCB6F43ACEE2
#define D25CB2E1_C813_4117_90A3_BCB6F43ACEE2

#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <filesystem>
#include <thread>
#include <mutex>

#include "GCD.hpp"
#include "Fibonacci.hpp"

class Tests {
public:
  Tests()
    : m_path{ std::filesystem::current_path() }
    , m_pGCD{ std::make_unique<Algorithms::GCD>() }
    , m_pFibonacci{ std::make_unique<Algorithms::Fibonacci>() }
  {}

  void Run();

private:
  template<typename T>
  T m_readFile(const std::filesystem::path& filename);
  void m_runFibonacci();
  void m_runGCD();

private:
  std::filesystem::path m_path;
  std::unique_ptr<Algorithms::GCD> m_pGCD;
  std::unique_ptr<Algorithms::Fibonacci> m_pFibonacci;
  std::mutex m_mutex;
};

#endif /* D25CB2E1_C813_4117_90A3_BCB6F43ACEE2 */
