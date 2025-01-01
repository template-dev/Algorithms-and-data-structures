#include <iostream>
#include <chrono>
#include "SingleArray.hpp"
#include "VectorArray.hpp"
#include "FactorArray.hpp"

int main() {
  try{
    DataStructure::SingleArray<int32_t> single;
    DataStructure::VectorArray<int32_t> vector;
    DataStructure::FactorArray<int32_t> factor;

    auto start = std::chrono::high_resolution_clock::now();
    for (int32_t i = 0; i < 50'000; ++i)
      single.push_back(i);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Single size: " << single.size() << std::endl;
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int32_t i = 0; i < 50'000; ++i)
      vector.push_back(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Vector size: " << vector.size() << std::endl;
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int32_t i = 0; i < 50'000; ++i)
      factor.push_back(i);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Factor size: " << factor.size() << ", capacity: " << factor.capacity() << std::endl;
    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms." << std::endl;
  }
  catch(const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
