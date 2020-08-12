#include <iostream>

int
main (int argc, char **argv)
{
  using namespace std;

  cout.setf (ios_base::fixed, ios_base::floatfield);

  float tree = 3;
  int guess (3.9832);
  int debt = 7.2E12;
  cout << "tree=" << tree << endl;
  cout << "guess=" << guess << endl;
  cout << "debt=" << debt << endl;

  int thorn = 12;
  long thorn_long = long (thorn);
  long thorn_long2 = (long) thorn;
  long thorn_long3 = static_cast<long> (thorn);
  cout << thorn << " " << thorn_long << " " << thorn_long2 << " " << thorn_long3
      << endl;

  return 0;
}
