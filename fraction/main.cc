#include <iostream>
using std::endl;
using std::cout;

#include "fraction.h"

int main(int arg, char** argv)  {
    Fraction f1(2,4), f2(3,9);
    Fraction f3 = f1.Add(f2);
    
    cout << f3.num() << "/" << f3.den() << endl;

    return 0;
}
