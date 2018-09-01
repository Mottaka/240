/* Homework 1 by Ian Osea, converts numbers to binary
   CSCE 240 Summer 2017
   May 16, 2017.
 */

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//main with variables declared.
int main(int argc, char** argv){
  
  string binary; 
  long bytes;
  long value;
  //input for and value.
  cin >> bytes >> value;

  //if input goes out of scope, it exits.
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
  //stores at the beginning of the string. Prepends.
  for(i =0; i!= bytes; ++i){
    remainder = value %2;
    
    binary.insert(0, to_string(remainder));
    //shifts by a 2's place.
    value/=2;
  }
  cout << binary << endl;


 }

