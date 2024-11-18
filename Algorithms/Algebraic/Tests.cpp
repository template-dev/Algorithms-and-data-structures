#include "Tests.hpp"

void Tests::Run() {
  std::thread th_fibonacci(&Tests::m_runFibonacci, this);
  std::thread th_gcd(&Tests::m_runGCD, this);

  th_fibonacci.join();
  th_gcd.join();
}

void Tests::m_runFibonacci() {
  std::lock_guard<std::mutex> _(m_mutex);
  std::cout << "---[ Fibonacci ]---" << std::endl;
  short iter{};
  int counter{1};
  while (true) {
    auto inputFile = m_path / "Fibo" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "Fibo" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile))
      return;

    int n = m_readFile<int>(inputFile);
    int64_t outputValue = m_readFile<int64_t>(outputFile);

    auto begin = std::chrono::steady_clock::now();
    int64_t solveResult = m_pFibonacci->Gold(n);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    if (solveResult == outputValue)
      std::cout << "Test " << iter << " OK";
    else
      std::cout << "Test " << iter << " ERROR: " << solveResult << " expected: " << outputValue;

    std::cout << " | The time: " << elapsed_ms.count() << " ms" << std::endl;

    ++iter;
    ++counter;
  }
}

void Tests::m_runGCD() {
  std::lock_guard<std::mutex> _(m_mutex);
  std::cout << "---[ GCD ]---" << std::endl;
  short iter{};
  int counter{1};
  while (true) {
    auto inputFile = m_path / "GCD" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "GCD" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile))
      return;

    int64_t m{};
    int64_t n{};

    std::ifstream file(inputFile);
    if (file.is_open()) {
      file >> m;
      file >> n;
      file.close();
    }

    int64_t outputValue = m_readFile<int64_t>(outputFile);

    auto begin = std::chrono::steady_clock::now();
    int64_t solveResult = m_pGCD->EuclidSubtractionIterative(m, n);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    if (solveResult == outputValue)
      std::cout << "Test " << iter << " OK";
    else
      std::cout << "Test " << iter << " ERROR: " << solveResult << " expected: " << outputValue;

    std::cout << " | The time: " << elapsed_ms.count() << " ms" << std::endl;

    ++iter;
    ++counter;
  }
}

template<typename T>
T Tests::m_readFile(const std::filesystem::path& filename) {
  std::ifstream file(filename);
  T data{};
  if(file.is_open()) {
    file >> data;
    file.close();
  } else {
    std::cerr << "The file could not be opened!" << std::endl;
    return false;
  }
  return data;
}
