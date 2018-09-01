#include "read_frac.h"

int main(int argc, char* argv[]) {
  if (argc < 4) {
    cout << "USAGE: read_frac in_file.fra out_file.fra scalar" << endl;
    return 1;
  }

  ifstream fin;
  fin.open(argv[1]);
  if ( fin.fail() ) {
    cout << argv[1] << " does not exist." << endl;
    return 2;
  }
  int count;
  fin >> count;
  Fraction *fracs = new Fraction[count];
  for (int i = 0; i < count; ++i)
    fin >> fracs[i];
  fin.close();

  ofstream fout;
  fout.open(argv[2], std::ios::app | std::ios::ate);
  int scalar = stoi(argv[3]);
  for (int i = 0; i < count; ++i)
    fout << (scalar * fracs[i]) << endl;
  fout.close();

  return 0;
}

