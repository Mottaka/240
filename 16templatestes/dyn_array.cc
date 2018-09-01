#include "dyn_array.h"

namespace csce240 {

  template<class T>
  DynamicArray::DynamicArray(const DynamicArray& other) {
    if (other.elements_ == nullptr) {
      elements_ = nullptr;
      size_ = 0;
      last_ = -1;
      return;
    }

    elements_ = new T[other.size_];
    size_ = other.size_;
    last_ = other.last_;

    for (int i = 0; i < size_; ++i)
      elements_[i] = other.elements_[i];
  }

  template<class T>
  const T DynamicArray<T>::Get(int index) const {
    assert(-1 < index && index <= last_);

	return elements_[index];
  }

  template<class T>
  void DynamicArray<T>::AddLast(T value) {
    if (elements_ == nullptr)
      elements_ = new T[DynamicArray::init_size_];
  
    if (last_ == size_ - 1)
      Grow();

    elements_[last_] = value;
	++last_;
  }

  template<class T>
  void DynamicArray<T>::AddFirst(T value) {
    if (elements_ == nullptr) {
      elements_ = new T[DynamicArray::init_size_];
      size_ = DynamicArray::init_size_;
    }

    if (last_ == size_ - 1)
      Grow();

    ++last_;
    for (int i = last_; i > 0; --i)
      elements_[i] = elements_[i-1];

    elements_[0] = value;
  }

  template<class T>
  void DynamicArray<T>::Grow() {
    assert(elements_ != nullptr);

    T *copy = new T[size_ * 2];
    for (int i = 0; i < size_; ++i)
      copy[i] = elements_[i];

    delete []elements_;
    elements_ = copy;

    size_ *= 2;
  }

  template<class T>
  const DynamicArray& DynamicArray::operator=(
                                    const DynamicArray& rhs) {
    if (this == &rhs)
      return *this;

    if (elements_ != nullptr)
      delete [] elements_;
      
    if (rhs.element_ == nullptr) {
      elements_ = nullptr;
      size_ = 0;
      last_ = -1;
      return *this;
    }

    elements_ = new T[rhs.size_];
    for (int i = 0; i < rhs.size_; ++i)
      elements_[i] = rhs.elements_[i];

    size_ = rhs.size_;
    last_ = rhs.last_;

    *this;
  }

} // namespace csce240
