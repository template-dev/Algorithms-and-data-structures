#ifndef B3557769_ADA7_43CA_A4C1_74A429F971AF
#define B3557769_ADA7_43CA_A4C1_74A429F971AF

#include <memory>
#include <stdexcept>
#include <initializer_list>

namespace DataStructure {
  template<typename T>
  class VectorArray {
  public:
    VectorArray();
    VectorArray(std::initializer_list<T> list);

    VectorArray(const VectorArray&) = delete;
    VectorArray(VectorArray&&) = delete;
    VectorArray& operator=(const VectorArray&) = delete;
    VectorArray& operator=(VectorArray&&) = delete;

    void push_back(const T& value);
    void insert(const T& value, int32_t index);
    T remove(size_t index);
    size_t size() const { return m_size; }

    T& operator[](const int32_t index);
    const T& operator[](const int32_t index) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const VectorArray<U>& obj);

  private:
    size_t m_size;
    size_t m_coeff;
    std::unique_ptr<T[]> m_data;
  };
}

#include "VectorArray.inl"

#endif /* B3557769_ADA7_43CA_A4C1_74A429F971AF */
