#include <iostream>
#include "Tests.hpp"

int main(int argc, char** argv) {
  std::unique_ptr<Tests> pTests = std::make_unique<Tests>();
  pTests->Run();

  return EXIT_SUCCESS;
}
