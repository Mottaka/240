#include "test_vector.h"


int main(int argc, char** argv) {
  vector<int> vec;
  vec.push_back(0); vec.push_back(1);
  vec.push_back(1); vec.push_back(2);
  vec.push_back(3); vec.push_back(5);
  vec.push_back(8); vec.push_back(11);
  vec.push_back(19); vec.push_back(30);
  
  TestPrintVectorAt(vec);
  TestPrintVectorIt(vec);
  //TestPrintVectorConstIt(vec);

  TestScaleVectorIt(vec);
  TestScaleVectorAt(vec);
  //TestScaleVectorConstIt(vec);

  return 0;
}

void TestPrintVectorAt(const vector<int>& v) {
  cout << "TestPrintVectorAt" << endl;

  cout << "  ";
  for (unsigned int i = 0; i < v.size(); ++i)
    cout << v.at(i) << " ";
  cout << endl;
}

void TestPrintVectorIt(vector<int>& v) {
  cout << "TestPrintVectorIt" << endl;

  cout << "  ";
  vector<int>::iterator it = v.begin();
  while (it != v.end())
    cout << *(it++) << " ";
  cout << endl;
}

void TestScaleVectorAt(const vector<int>& v) {
  cout << "TestScaleVectorAt" << endl;

  double s;
  cout << "  Enter a scalar: ";
  cin >> s;

  cout << "  ";
  for (unsigned int i = 0; i < v.size(); ++i)
    cout << s * v.at(i) << " ";
  cout << endl;
}

void TestScaleVectorIt(vector<int>& v) {
  cout << "TestScaleVectorIt" << endl;

  double s;
  cout << "  Enter a scalar: ";
  cin >> s;

  cout << "  ";
  vector<int>::iterator it = v.begin();
  while (it != v.end()) {
    *it = s * *it;
    cout << *(it++) << " ";
  }
  cout << endl;
}


