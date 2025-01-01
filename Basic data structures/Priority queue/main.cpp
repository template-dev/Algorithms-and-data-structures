#include <iostream>
#include "PriorityQueue.hpp"

int main() {
  try {
    DataStructure::PriorityQueue<int32_t> queue;
    queue.enqueue(2, 25);
    queue.enqueue(5, 12);
    queue.enqueue(1, 75);
    queue.enqueue(3, 175);
    queue.enqueue(4, 172);
  }
  catch(const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
