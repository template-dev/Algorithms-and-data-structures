#include <iostream>
#include "SingleArray.hpp"

int main() {
  try{
    std::cout << "Single Array:" << std::endl;
    DataStructure::SingleArray<int32_t> single{1, 2, 3};
    std::cout << single << std::endl;
    single.push_back(4);
    std::cout << single << std::endl;
    single.insert(0, 0);
    std::cout << single << std::endl;
    std::cout << "Removed element: " << single.remove(0) << std::endl;
    std::cout << single << std::endl;

    std::cout << "Vector Array" << std::endl;
    DataStructure::SingleArray<int32_t> vec{1, 2, 3};
    std::cout << vec << std::endl;
    vec.push_back(4);
    std::cout << vec << std::endl;
    vec.insert(0, 0);
    std::cout << vec << std::endl;
    std::cout << "Removed element: " << vec.remove(0) << std::endl;
    std::cout << vec << std::endl;
  }
  catch(const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
