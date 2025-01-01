#ifndef D7A637B4_F0F2_4AC6_9473_78A39FB08248
#define D7A637B4_F0F2_4AC6_9473_78A39FB08248

#include <list>
#include <vector>

namespace DataStructure {
  template<typename T>
  class PriorityQueue {
  public:
    PriorityQueue();

    PriorityQueue(const PriorityQueue&) = delete;
    PriorityQueue(PriorityQueue&&) = delete;
    PriorityQueue& operator=(const PriorityQueue&) = delete;
    PriorityQueue& operator=(PriorityQueue&&) = delete;

    void enqueue(short priority, T item);
    T dequeue();

    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue& pq) {
      for (short i = pq.m_maxPriority; i >= 0; --i) {
        os << "Priority " << i << ": ";
        for (const auto& item : pq.m_queue[i]) {
          os << item << " ";
        }
        os << std::endl;
      }
      return os;
    }

  private:
    std::vector<std::list<T>> m_queue;
    short m_maxPriority;
  };
}

#include "PriorityQueue.inl"

#endif /* D7A637B4_F0F2_4AC6_9473_78A39FB08248 */
