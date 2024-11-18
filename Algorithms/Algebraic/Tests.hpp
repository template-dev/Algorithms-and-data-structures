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
#include "Power.hpp"

class Tests {
public:
  Tests()
    : m_path{ std::filesystem::current_path() }
    , m_pGCD{ std::make_unique<Algorithms::GCD>() }
    , m_pFibonacci{ std::make_unique<Algorithms::Fibonacci>() }
    , m_pPower{ std::make_unique<Algorithms::Power>() }
  {}

  void Run();

private:
  template<typename T>
  T m_readFile(const std::filesystem::path& filename);
  void m_runFibonacci();
  void m_runGCD();
  void m_runPower();

private:
  std::filesystem::path m_path;
  std::unique_ptr<Algorithms::GCD> m_pGCD;
  std::unique_ptr<Algorithms::Fibonacci> m_pFibonacci;
  std::unique_ptr<Algorithms::Power> m_pPower;
  std::mutex m_mutex;
};

#endif /* D25CB2E1_C813_4117_90A3_BCB6F43ACEE2 */
