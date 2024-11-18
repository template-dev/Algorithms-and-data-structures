#include <iostream>
#include "Tests.hpp"

int main(int argc, char** argv) {
  try {
    std::unique_ptr<Tests> pTests = std::make_unique<Tests>();
    pTests->Run();
  }
  catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
