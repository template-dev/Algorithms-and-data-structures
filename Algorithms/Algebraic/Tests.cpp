#include "Tests.hpp"

void Tests::Run() {
  std::thread th_fibonacci(&Tests::m_runFibonacci, this);
  std::thread th_gcd(&Tests::m_runGCD, this);
  std::thread th_power(&Tests::m_runPower, this);
  std::thread th_prime(&Tests::m_runPrime, this);

  th_fibonacci.join();
  th_gcd.join();
  th_power.join();
  th_prime.join();
}

void Tests::m_runFibonacci() {
  std::lock_guard<std::mutex> _(m_mutex);
  std::cout << "---[ Fibonacci ]---" << std::endl;
  short iter{};
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
  }
}

void Tests::m_runGCD() {
  std::lock_guard<std::mutex> _(m_mutex);
  std::cout << "---[ GCD ]---" << std::endl;
  short iter{};
  while (true) {
    auto inputFile = m_path / "GCD" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "GCD" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile))
      return;

    std::string checkFirstParam;
    std::string checkSecondParam;
    int64_t m{};
    int64_t n{};

    std::ifstream file(inputFile);
    if (file.is_open()) {
      file >> checkFirstParam;
      file >> checkSecondParam;
      file.close();
    }

    if(!isValidInt64(checkFirstParam, m)) {
      break;
    }

    m = std::stoll(checkFirstParam);
    n = std::stoll(checkSecondParam);

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

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile))
      return;

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
  std::cout << "---[ Prime ]---" << std::endl;
  short iter{};
  while (true) {
    auto inputFile = m_path / "Primes" / "test." += std::to_string(iter) + ".in";
    auto outputFile = m_path / "Primes" / "test." += std::to_string(iter) + ".out";

    if (!std::filesystem::exists(inputFile) || !std::filesystem::exists(outputFile))
      return;

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

template<>
int64_t Tests::m_readFile<int64_t>(const std::filesystem::path& filename) {
  std::ifstream file(filename);
  int64_t data{};
  std::string checkData;
  if(file.is_open()) {
    file >> checkData;
    file.close();
  } else {
    std::cerr << "The file could not be opened!" << std::endl;
    return false;
  }

  if (isValidInt64(checkData, data))
    data = std::stoll(checkData);
  else
    return -1;

  return data;
}

bool Tests::isValidInt64(const std::string& str, int64_t& result) {
  try {
    size_t pos;
    long long value = std::stoll(str, &pos);

    if (pos != str.size()) {
        return false;
    }

    if (value < std::numeric_limits<int64_t>::min() || value > std::numeric_limits<int64_t>::max()) {
        return false;
    }

    result = static_cast<int64_t>(value);
    return true;
  } catch (const std::exception& e) {
      std::cerr << e.what() << std::endl;
      return false;
  }
}
