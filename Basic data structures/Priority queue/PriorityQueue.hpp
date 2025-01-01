#ifndef D7A637B4_F0F2_4AC6_9473_78A39FB08248
#define D7A637B4_F0F2_4AC6_9473_78A39FB08248

#include <list>
#include <vector>

namespace DataStructure {
  template<typename T>
  class PriorityQueue {
  public:
    PriorityQueue();

    void enqueue(short priority, T item);
    T dequeue();

  private:
    std::vector<std::list<T>> m_queue;
    short m_maxPriority;
  };
}

#include "PriorityQueue.inl"

#endif /* D7A637B4_F0F2_4AC6_9473_78A39FB08248 */
