#ifndef _240_LECT_TEST_DYN_ARRAY_H_
#define _240_LECT_TEST_DYN_ARRAY_H_

#include <iostream>
using std::endl;
using std::cout;
#include <string>
using std::string;
using std::to_string;

#include "dyn_array.cc"
using csce240::DynamicArray;

class DynamicArrayTest {
 public:
  bool TestAddFirst();
  bool TestAddLastWithSize();
  bool TestGet();

 private:
  const int elems_[9] = {1, 2, 3, 5, 7, 11, 13, 17, 19};
  const int size_ = 9;
};

int main(int argc, char** argv);


#endif
