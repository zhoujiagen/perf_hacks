#include <iostream>
#include <climits>

using namespace std;

int
main (int argc, char **argv)
{
  cout << sizeof(bool) << endl;

  cout << sizeof(short) << " " << sizeof(signed short) << " "
      << sizeof(unsigned short) << endl;

  cout << sizeof(char) << " " << sizeof(signed char) << " "
      << sizeof(unsigned char) << endl;

  cout << sizeof(int) << " " << sizeof(signed int) << " "
      << sizeof(unsigned int) << endl;

  cout << sizeof(long) << " " << sizeof(signed long) << " "
      << sizeof(unsigned long) << endl;

  cout << sizeof(long long) << " " << sizeof(signed long long) << " "
      << sizeof(unsigned long long) << endl;

  cout << sizeof(float) << " " << 1.2f << endl;
  cout << sizeof(double) << " " << 1.2 << endl;
  cout << sizeof(long double) << " " << 1.2l << endl;

  cout << endl;

  bool n_bool = true;
  n_bool = false;
  short n_short = SHRT_MAX;
  char n_char = CHAR_MAX;
  int n_int = INT_MAX;
  long n_long = LONG_MAX;
  long long n_llong = LLONG_MAX;

  cout << n_bool << " " << sizeof n_bool << endl;
  cout << n_short << " " << sizeof n_short << endl;
  cout << n_char << " " << (int) n_char << " " << sizeof n_char << endl;
  cout << n_int << " " << sizeof n_int << endl;
  cout << n_long << " " << sizeof n_long << endl;
  cout << n_llong << " " << sizeof n_llong << endl;

  return 0;
}
