#include "test_int_list.h"

int main(int argc, char** argv) {
  IntList *l1 = new IntList();
  l1->PushFront(3);
  l1->PushBack(13);
  l1->PushFront(23);
  l1->PushBack(43);
  IntList l2(*l1), l3;
  cout << "Are l1 and l2 same obj? " <<
          (l1 == &l2 ? "yes" : "no") << endl;
  l3 = *l1;
  cout << "Are l1 and l3 same obj? " <<
          (l1 == &l3 ? "yes" : "no") << endl;

  cout << "l1: " << *l1 << endl;
  cout << "l2: " << l2 << endl;
  cout << "l3: " << l3 << endl;

  cout << "Pushing 73 to front of l2" << endl;
  l2.PushFront(73);
  cout << "l1: " << *l1 << endl;
  cout << "l2: " << l2 << endl;

  cout << "Pushing 53 to back of l3" << endl;
  l3.PushBack(53);
  cout << "l1: " << *l1 << endl;
  cout << "l3: " << l3 << endl;

  cout << "Popped " << l2.PopBack() << " from back of l2." << endl;
  cout << "l2: " << l2 << endl;

  cout << "Popped " << l3.PopFront() << " from front of l2." << endl;
  cout << "l3: " << l3 << endl;

  return 0;
}

