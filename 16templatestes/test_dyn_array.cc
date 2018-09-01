#include "test_dyn_array.h"

int main(int argc, char** argv) {
  DynamicArrayTest unit_tester;


  if (!unit_tester.TestAddFirst())
    cout << "  FAILED" << endl;
  else
    cout << "  PASSED" << endl;

  if (!unit_tester.TestAddLastWithSize())
    cout << "  FAILED" << endl;
  else
    cout << "  PASSED" << endl;

  if (!unit_tester.TestGet())
    cout << "  FAILED" << endl;
  else
    cout << "  PASSED" << endl;
}

bool DynamicArrayTest::TestAddFirst() {
  cout << "TestAddFirst" << endl;
  DynamicArray<int> dyna;

  int i;
  for (i = 0; i < size_; ++i)
    dyna.AddFirst(elems_[i]);

  cout << "  Added first " << i << " of " << size_ << endl;

  return true;
}

bool DynamicArrayTest::TestAddLastWithSize() {
  cout << "TestAddLastWithSize" << endl;
  DynamicArray<int> array(size_);
  int i;
  for (i = 0; i < size_; ++i) 
    array.AddLast(elems_[i]);
  
  cout << "  Added last " << i << " of " << size_ << endl;

  return true;
}

bool DynamicArrayTest::TestGet() {
  cout << "TestGet" << endl;
  DynamicArray<int> dyna(size_);
  string from_array(""), from_dyna("");

  from_array += to_string(elems_[0]);
  dyna.AddLast(elems_[0]);
  from_dyna += to_string(dyna.Get(0));

  for (int i = 1; i < size_; ++i) {
    from_array += " " + to_string(elems_[i]);
    dyna.AddLast(elems_[i]);
	from_dyna += " " + to_string(dyna.Get(i));
  }

  cout << "  Expected: " << from_array;
  cout << "  Actual: " << from_dyna << endl;

  return from_array == from_dyna;
}

