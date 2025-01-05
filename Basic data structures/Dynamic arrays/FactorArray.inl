#include "FactorArray.hpp"

namespace DataStructure {
  template<typename T>
  FactorArray<T>::FactorArray()
      : m_size(0)
      , m_capacity{0}
      , m_data{nullptr}
  {}

  template<typename T>
  FactorArray<T>::FactorArray(std::initializer_list<T> list)
      : m_size{list.size()}
      , m_capacity{m_size * 2}
      , m_data{std::make_unique<T[]>(m_capacity){}} {
    std::copy(list.begin(), list.end(), m_data);
  }

  template<typename T>
  T& FactorArray<T>::operator[](const int32_t index) {
    if (index < 0 || index >= m_size)
      throw std::out_of_range("Index out of range");
    return m_data[index];
  }

  template<typename T>
  const T& FactorArray<T>::operator[](const int32_t index) const {
    if (index < 0 || index >= m_size)
      throw std::out_of_range("Index out of range");
    return m_data[index];
  }

  template<typename T>
  void FactorArray<T>::push_back(const T& value) {
    if (empty()) {
      m_capacity = 2;
      m_data = std::make_unique<T[]>(m_capacity);
    } else if(m_size == m_capacity) {
      m_capacity *= 2;
      std::unique_ptr<T[]> tmp = std::make_unique<T[]>(m_capacity);
      for (size_t i = 0; i < m_size; ++i)
        tmp[i] = std::move(m_data[i]);
      m_data = std::move(tmp);
    }
    m_data[m_size++] = value;
  }

  template<typename T>
  void FactorArray<T>::insert(const T& value, int32_t index) {
    if (index < 0 || index > m_size || empty())
      throw std::out_of_range("Index out of range");
    if(m_size == m_capacity) {
      m_capacity *= 2;
      std::unique_ptr<T[]> tmp = std::make_unique<T[]>(m_capacity);
      for (size_t i = 0; i < m_size; ++i)
        tmp[i] = std::move(m_data[i]);
      m_data = std::move(tmp);
    }
    for (size_t i = m_size; i > static_cast<size_t>(index); --i)
        m_data[i] = std::move(m_data[i - 1]);
    m_data[index] = value;
    ++m_size;
  }

  template<typename T>
  T FactorArray<T>::remove(size_t index) {
    if (index < 0 || index >= m_size)
      throw std::out_of_range("Index out of range");
    T removeElement = std::move(m_data[index]);
    for (size_t i = index; i < m_size - 1; ++i)
      m_data[i] = std::move(m_data[i + 1]);
    --m_size;
    if (m_size > 0 && m_size <= m_capacity / 4) {
        m_capacity /= 2;
        std::unique_ptr<T[]> tmp = std::make_unique<T[]>(m_capacity);
        for (size_t i = 0; i < m_size; ++i)
            tmp[i] = std::move(m_data[i]);
        m_data = std::move(tmp);
    }
    return removeElement;
  }

  template<typename T>
  std::ostream& operator<<(std::ostream& os, const FactorArray<T>& obj) {
    size_t size = obj.size();
    for (int32_t i = 0; i < size; ++i)
      os << obj[i] << " ";
    return os;
  }
}
