#include "InsertionSort.hpp"

void Sort::Insertion(std::vector<int>& vec) {
  for (size_t i = 1; i < vec.size(); ++i)
    for (size_t j = i; j > 0 && vec[j] < vec[j - 1]; --j)
      std::swap(vec[j], vec[j - 1]);
}
