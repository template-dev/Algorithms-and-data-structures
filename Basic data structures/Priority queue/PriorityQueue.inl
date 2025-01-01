#include "PriorityQueue.hpp"

namespace DataStructure {
  template<typename T>
  PriorityQueue<T>::PriorityQueue()
    : m_queue{}
    , m_maxPriority{5}
  {}

  template<typename T>
  void PriorityQueue<T>::enqueue(short priority, T item) {
    if (priority <= 0 || priority > m_maxPriority)
      throw std::invalid_argument("The maximum priority must be greater than 0 and less than 5");
  }

  template<typename T>
  T PriorityQueue<T>::dequeue() {
    return T{};
  }
}
