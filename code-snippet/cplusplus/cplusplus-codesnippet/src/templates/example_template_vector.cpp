#include <vector>
#include <iostream>

int
main (int argc, char **argv)
{
  using namespace std;

  vector<int> vec_int;
  cout << vec_int.empty () << endl;

  vector<double> vec_double =
    { 1, 2, 3 };
  cout << vec_double[0] << ", " << vec_double[1] << endl;

  int n = 10;
  vector<double> vec_double2 (n);
  vec_double2[0] = 10;
  cout << vec_double2[0] << ", " << vec_double2[1] << endl;

  return 0;
}
