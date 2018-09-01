#include "intro.h"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    cout << "USAGE: intro file.in file.out" << endl;
    return 1;
  }

  random_device gen;
  int roll1, roll2;

  ifstream fin;
  fin.open(argv[1]);
  ofstream fout;
  fout.open(argv[2]);

  string str_num = "";
  char byte;
  fin.get(byte);
  while (!fin.eof()) {
    if ('0' <= byte && byte <= '9')
      str_num = str_num + byte;
    else {
      cout << "Read a " << str_num << endl;
      fout << 2*stoi(str_num) << endl;
      str_num = "";
    }

    fin.get(byte);
  }

  return 0;

  do {
    roll1 = gen()%100 + 1;
    roll2 = gen()%100 + 1;

    cout << roll1 << ", " << roll2 << endl;
    fout << roll1 << endl;
  } while (roll1 != 1 || roll2 != 100);

  fout.close();

  return 0;
}

