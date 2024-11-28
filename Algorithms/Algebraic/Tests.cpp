#include "Tests.hpp"

void Tests::Run() {
  //std::thread th_fibonacci(&Tests::m_runFibonacci, this);
  std::thread th_gcd(&Tests::m_runGCD, this);
  //std::thread th_power(&Tests::m_runPower, this);
  //std::thread th_prime(&Tests::m_runPrime, this);

  //th_fibonacci.join();
  th_gcd.join();
  //th_power.join();
  //th_prime.join();
}

void Tests::m_runFibonacci() {
  std::lock_guard<std::mutex> _(m_mutex);
  std::cout << "---[ Fibonacci ]---" << std::endl;
  short iter{};
  while (true) {
    auto inputFile = m_path / "Fibo" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "Fibo" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile)) {
      std::cerr << "File(s) " << inputFile.filename() << " or " << outputFile.filename() << " not found!" << std::endl;
      return;
    }

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
  }
}

void Tests::m_runGCD() {
  std::lock_guard<std::mutex> _(m_mutex);
  std::cout << "---[ GCD ]---" << std::endl;
  short iter{};
  while (true) {
    auto inputFile = m_path / "GCD" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "GCD" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile)) {
      std::cerr << "File(s) " << inputFile.filename() << " or " << outputFile.filename() << " not found!" << std::endl;
      return;
    }

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
  }
}

void Tests::m_runPower() {
  std::lock_guard<std::mutex> _(m_mutex);
  std::cout << "---[ Power ]---" << std::endl;
  short iter{};
  while (true) {
    auto inputFile = m_path / "Power" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "Power" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile)) {
      std::cerr << "File(s) " << inputFile.filename() << " or " << outputFile.filename() << " not found!" << std::endl;
      return;
    }

    long double m{};
    int64_t n{};

    std::ifstream file(inputFile);
    if (file.is_open()) {
      file >> m;
      file >> n;
      file.close();
    }

    double outputValue = m_readFile<double>(outputFile);

    auto begin = std::chrono::steady_clock::now();
    double solveResult = m_pPower->PowerOptimized(m, n);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    if (std::to_string(solveResult) == std::to_string(outputValue))
      std::cout << "Test " << iter << " OK";
    else
      std::cout << "Test " << iter << " ERROR: " << solveResult << " expected: " << outputValue;

    std::cout << " | The time: " << elapsed_ms.count() << " ms" << std::endl;

    ++iter;
  }
}

void Tests::m_runPrime() {
  std::lock_guard<std::mutex> _(m_mutex);
  std::cout << "---[ Power ]---" << std::endl;
  short iter{};
  while (true) {
    auto inputFile = m_path / "Power" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "Power" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile)) {
      std::cerr << "File(s) " << inputFile.filename() << " or " << outputFile.filename() << " not found!" << std::endl;
      return;
    }
    std::cout << inputFile << "\n" << outputFile << std::endl;

    int32_t inputValue = m_readFile<int32_t>(inputFile);
    int32_t outputValue = m_readFile<int32_t>(outputFile);

    auto begin = std::chrono::steady_clock::now();
    int32_t solveResult = m_pPrimes->Eratosphene(inputValue);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    if (solveResult == outputValue)
      std::cout << "Test " << iter << " OK";
    else
      std::cout << "Test " << iter << " ERROR: " << solveResult << " expected: " << outputValue;

    std::cout << " | The time: " << elapsed_ms.count() << " ms" << std::endl;

    ++iter;
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
