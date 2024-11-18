#include "selectionSort.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::vector<int> arr{1, 3, 2, 4, 7, 0};
  sorts::selection_sort(arr);
  
  for(const auto& item : arr) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}