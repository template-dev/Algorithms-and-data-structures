#include "VectorArray.hpp"

namespace DataStructure {
  template<typename T>
  VectorArray<T>::VectorArray()
      : m_size(0)
      , m_coeff{100}
      , m_data{nullptr}
  {}

  template<typename T>
  VectorArray<T>::VectorArray(std::initializer_list<T> list)
      : m_size{list.size()}
      , m_coeff{100}
      , m_data{std::make_unique<T[]>(m_size){}} {
    std::copy(list.begin(), list.end(), m_data);
  }

  template<typename T>
  T& VectorArray<T>::operator[](const int32_t index) {
    if (index < 0 || index >= m_size)
      throw std::out_of_range("Index out of range");
    return m_data[index];
  }

  template<typename T>
  const T& VectorArray<T>::operator[](const int32_t index) const {
    if (index < 0 || index >= m_size)
      throw std::out_of_range("Index out of range");
    return m_data[index];
  }

  template<typename T>
  void VectorArray<T>::push_back(const T& value) {
    if (empty()) {
      m_data = std::make_unique<T[]>(m_coeff);
      m_data[m_size++] = value;
    } else {
      std::unique_ptr<T[]> tmp = std::make_unique<T[]>(m_size + m_coeff);
      for (int32_t i = 0; i < m_size; ++i)
        tmp[i] = std::move(m_data[i]);
      tmp[m_size++] = value;
      m_data = std::move(tmp);
    }
  }

  template<typename T>
  void VectorArray<T>::insert(const T& value, int32_t index) {
    if (index < 0 || index > m_size)
      throw std::out_of_range("Index out of range");
    std::unique_ptr<T[]> tmp = std::make_unique<T[]>(m_size + m_coeff);
    for (size_t i = 0; i < m_size; ++i)
      tmp[i] = std::move(m_data[i]);
    for (size_t i = m_size; i > index; --i)
      tmp[i] = std::move(tmp[i - 1]);
    tmp[index] = value;
    ++m_size;
    m_data = std::move(tmp);
  }

  template<typename T>
  T VectorArray<T>::remove(size_t index) {
    if (index < 0 || index >= m_size)
      throw std::out_of_range("Index out of range");
    T removeElement = std::move(m_data[index]);
    for (size_t i = index; i < m_size - 1; ++i)
      m_data[i] = std::move(m_data[i + 1]);
    --m_size;
    std::unique_ptr<T[]> tmp = std::make_unique<T[]>(m_size);
    for (size_t i = 0; i < m_size; ++i)
      tmp[i] = std::move(m_data[i]);
    m_data = std::move(tmp);
    return removeElement;
  }

  template<typename T>
  std::ostream& operator<<(std::ostream& os, const VectorArray<T>& obj) {
    size_t size = obj.size();
    for (int32_t i = 0; i < size; ++i)
      os << obj[i] << " ";
    return os;
  }
}
