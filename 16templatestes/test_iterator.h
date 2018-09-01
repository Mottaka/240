#ifndef _240_LECT_16TEMPLATES_TEST_ITERATOR_H_
#define _240_LECT_16TEMPLATES_TEST_ITERATOR_H_

#include <iostream>
using std::cout;
#include <iterator>
using std::iterator;
using std::input_iterator_tag;


class Iterator : public iterator<input_iterator_tag, int>
{
  int *p_;
 public:
  Iterator(int* x) :p_(x) {}
  Iterator(const Iterator& mit) : p_(mit.p_) {}

  Iterator& operator++();
  Iterator operator++(int);

  bool operator==(const Iterator& rhs) const;
  bool operator!=(const Iterator& rhs) const;
  int& operator*();
};

int main(int argc, char** argv);

#endif
