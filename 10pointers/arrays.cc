#include "arrays.h"


typedef int* intptr;
typedef double* dblptr;

int main(int argc, char** argv) {
  for (int i = 1; i < argc; ++i)
    cout << argv[i] << endl;

  int size, count, grade;
  size = 2;
  dblptr grades = new double[size];
  count = 0;
  cout << "Enter a grade (negative to quit): ";
  cin >> grade;
  while (grade >= 0.0) {
    if ( count >= size ) { // grow array
      dblptr tmp = new double[2*size];

      for (int i=0; i<size; ++i)
        tmp[i] = grades[i];
      size *= 2;
      delete []grades;
      grades = tmp;
    }
    grades[count] = grade;
    ++count;

    cout << "Enter a grade (negative to quit): ";
    cin >> grade;
  }

  cout << "You entered " << count << " grades" << endl;
  for (int i=0; i < count; ++i)
    cout << "Grade " << i << "): " << grades[i] << endl;


  return 0;
}

