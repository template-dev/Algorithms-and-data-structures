#include "PriorityQueue.hpp"

namespace DataStructure {
  template<typename T>
  PriorityQueue<T>::PriorityQueue()
    : m_queue{}
    , m_maxPriority{5}
  {}

  template<typename T>
  void PriorityQueue<T>::enqueue(short priority, T item) {
    if (priority < 0 || priority > m_maxPriority)
      throw std::invalid_argument("The maximum priority must be greater than 0 and less than 5");
    m_queue[priority].emplace_back(item);
  }

  template<typename T>
  T PriorityQueue<T>::dequeue() {
    for (short i = m_maxPriority; i >= 0; --i) {
      if (!m_queue[i].empty()) {
        T item = m_queue[i].front();
        m_queue[i].pop_front();
        return item;
      }
    }
    throw std::runtime_error("Priority queue is empty");
  }

  template<typename T>
  std::ostream& operator<<(std::ostream& os, const PriorityQueue<T>& pq) {
    for (short i = pq.m_maxPriority; i >= 0; --i) {
      os << "Priority " << i << ": ";
      for (const auto& item : pq.m_queue[i]) {
        os << item << " ";
      }
      os << std::endl;
    }
    return os;
  }
}
