#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv){
  
  string binary; 
  long bytes;
  long value;

  cin >> bytes >> value;

 
  if (bytes < 0) 
    exit(1);
  if (bytes > 32)
    exit(1);
  if (value < 0)
    exit(2);
  if (value > 4294967296)
    exit(2);

  int i;
  int remainder = 0;
  for(i =0; i!= bytes; ++i){
    remainder = value %2;
    
    binary.insert(0, to_string(remainder));
    
    value/=2;
  }
  cout << binary << endl;


 }
