#include "Bubble.hpp"

void Sort::Bubble(std::vector<int>& vec) {
  for (size_t i = vec.size() - 1; i > 0; --i)
    for(size_t j = 0; j < i; ++j)
      if (vec[j] > vec[j + 1])
        std::swap(vec[j], vec[j + 1]);
}
