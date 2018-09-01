#ifndef BASE_CONVERTER_H_
#define BASE_CONVERTER_H_

#include <cctype>
#include<string>
using std::string;
using std::to_string;

class BaseConverter {

public:
  BaseConverter(int base10);  
  
  string GetUnsignedBase2(int bits);
  string GetSignedBase2(int bits);
  string GetBase16();
  int GetBase10();

  void SetUnsignedBase2(string base_2);
  void SetSignedBase2(string base_2);
  void SetBase16(string base_16);
  void SetBase10(int base_10);

private:
  int base_10_;

};

#endif
