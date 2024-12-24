#include <iostream>
#include "SingleArray.hpp"
#include "VectorArray.hpp"
#include "FactorArray.hpp"

int main() {
  try{
    std::cout << "---[ Single Array ]---" << std::endl;
    DataStructure::SingleArray<int32_t> single{1, 2, 3};
    std::cout << single << " | size: " << single.size() << std::endl;
    single.push_back(4);
    std::cout << single << " | size: " << single.size() << std::endl;
    single.insert(0, 0);
    std::cout << single << " | size: " << single.size() << std::endl;
    std::cout << "Removed element: " << single.remove(0) << std::endl;
    std::cout << single << " | size: " << single.size() << std::endl;

    std::cout << "\n---[ Vector Array ]---" << std::endl;
    DataStructure::VectorArray<int32_t> vec{1, 2, 3};
    std::cout << vec << " | size: " << vec.size() << std::endl;
    vec.push_back(4);
    std::cout << vec << " | size: " << vec.size() << std::endl;
    vec.insert(0, 0);
    std::cout << vec << " | size: " << vec.size() << std::endl;
    std::cout << "Removed element: " << vec.remove(0) << std::endl;
    std::cout << vec << " | size: " << vec.size() << std::endl;

    std::cout << "\n---[ Factor Array ]---" << std::endl;
    DataStructure::FactorArray<int32_t> factor{1};
    std::cout << factor << " | size: " << factor.size() << ", capacity: " << factor.capacity() << std::endl;
    factor.push_back(4);
    std::cout << factor << " | size: " << factor.size() << ", capacity: " << factor.capacity() << std::endl;
    factor.insert(0, 0);
    std::cout << factor << " | size: " << factor.size() << ", capacity: " << factor.capacity() << std::endl;
    std::cout << "Removed element: " << factor.remove(0) << std::endl;
    std::cout << factor << " | size: " << factor.size() << ", capacity: " << factor.capacity() << std::endl;
  }
  catch(const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
