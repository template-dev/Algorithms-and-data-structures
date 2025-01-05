#ifndef CEFDA208_5BAD_4818_B741_AFF3B878EE6B
#define CEFDA208_5BAD_4818_B741_AFF3B878EE6B

#include <memory>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>

namespace DataStructure {
  template<typename T>
  class FactorArray {
  public:
    FactorArray();
    FactorArray(std::initializer_list<T> list);

    FactorArray(const FactorArray&) = delete;
    FactorArray(FactorArray&&) = delete;
    FactorArray& operator=(const FactorArray&) = delete;
    FactorArray& operator=(FactorArray&&) = delete;

    void push_back(const T& value);
    void insert(const T& value, int32_t index);
    T remove(size_t index);
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    bool empty() const { return m_size == 0; }

    T& operator[](const int32_t index);
    const T& operator[](const int32_t index) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const FactorArray<U>& obj);

  private:
    size_t m_size;
    size_t m_capacity;
    std::unique_ptr<T[]> m_data;
  };
}

#include "FactorArray.inl"

#endif /* CEFDA208_5BAD_4818_B741_AFF3B878EE6B */
