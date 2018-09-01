#include "test_iterator.h"

Iterator& Iterator::operator++() {
  ++p_;
  return *this;
}
Iterator Iterator::operator++(int) {
  Iterator tmp(*this);
  ++p_;
  return tmp;
}

bool Iterator::operator==(const Iterator& rhs) const {
  return p_ == rhs.p_;
}
bool Iterator::operator!=(const Iterator& rhs) const {
  return p_ != rhs.p_;
}

int& Iterator::operator*() {
  return *p_;
}

int main(int argc, char** argv) {
  int numbers[]={10,20,30,40,50};
  Iterator from(numbers);
  Iterator until(numbers+5);
  for (Iterator it=from; it!=until; it++)
    std::cout << *it << ' ';
  std::cout << '\n';

  return 0;
}
