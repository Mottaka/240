#ifndef _240_LECT_DYN_ARRAY_H_
#define _240_LECT_DYN_ARRAY_H_

#include <cassert>
#include <iostream>
using std::endl;
using std::cout;

namespace csce240 {

  template<class T>
  class DynamicArray {
   public:
    DynamicArray(): elements_(nullptr), size_(0), last_(-1) {};
    DynamicArray(int size) :
	  elements_(new T[size]), size_(size), last_(0) {};
    DynamicArray(T* elements, int size);
    DynamicArray(const DynamicArray& other);
    inline ~DynamicArray() { delete [] elements; };
  
    unsigned char Init(T* elems, int size);
  
    // accessors
    const T Get(int index) const;
    const T First() const;
    const T Last() const;
  
    // modifiers
    bool Assign(int index, T value);
    void AddFirst(T value);
    void AddLast(T value);
    bool Insert(int index, T elem);
    bool erase(int index);

    const DynamicArray& operator=(const DynamicArray& rhs);

   protected:
    void Grow();

    T *elements_;
    int size_;
    int last_; // index of last given value
    const static int init_size_ = 2;
  };
} // namespace csce240
#endif
