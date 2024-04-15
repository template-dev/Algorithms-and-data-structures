#ifndef ALGORITHMS_AND_DATA_STRUCTURES_SELECTIONSORT_H
#define ALGORITHMS_AND_DATA_STRUCTURES_SELECTIONSORT_H

#include <algorithm>
#include <vector>

namespace sorts {
  void selection_sort(std::vector<int> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
      size_t minIndex = i;
      for (size_t j = i + 1; j < arr.size(); ++j) {
        if (arr[minIndex] > arr[j]) {
          minIndex = j;
        }
      }
      std::swap(arr[i], arr[minIndex]);
    }
  }
}

#endif //ALGORITHMS_AND_DATA_STRUCTURES_SELECTIONSORT_H
