#include "ShellSort.hpp"

void Sort::Shell(std::vector<int>& vec) {
    for (size_t gap = vec.size() / 2; gap > 0; gap /= 2)
        for (size_t i = gap; i < vec.size(); ++i)
            for (size_t j = i; j >= gap && vec[j] < vec[j - gap]; j -= gap)
                std::swap(vec[j], vec[j - gap]);
}
