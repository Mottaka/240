#include "eof.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "Usage: eof input_file.in output_file.out" << endl;
	return 1;
  }

  ifstream fin;
  fin.open(argv[1]);
  ofstream fout;
  fout.open(argv[2]);

  char byte;
  fin.get(byte);
  while (!fin.eof()) {
	fout << byte << '\n';

	fin.get(byte);
  }
  
  fin.close();
  fout.close();

  return 0;
}

