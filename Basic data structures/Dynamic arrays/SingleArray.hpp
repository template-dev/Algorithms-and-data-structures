#ifndef DE3D54C5_149C_4097_B321_999CC1B641AB
#define DE3D54C5_149C_4097_B321_999CC1B641AB

#include <memory>
#include <stdexcept>
#include <initializer_list>

namespace DataStructure {
  template<typename T>
  class SingleArray {
  public:
    SingleArray();
    SingleArray(std::initializer_list<T> list);

    SingleArray(const SingleArray&) = delete;
    SingleArray(SingleArray&&) = delete;
    SingleArray& operator=(const SingleArray&) = delete;
    SingleArray& operator=(SingleArray&&) = delete;

    void push_back(const T& value);
    void insert(const T& value, int32_t index);
    T remove(size_t index);
    size_t size() const { return m_size; }
    bool empty() const { return m_size == 0; }

    T& operator[](const int32_t index);
    const T& operator[](const int32_t index) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const SingleArray<U>& obj);

  private:
    size_t m_size;
    size_t m_coeff;
    std::unique_ptr<T[]> m_data;
  };
}

#include "SingleArray.inl"

#endif /* DE3D54C5_149C_4097_B321_999CC1B641AB */
