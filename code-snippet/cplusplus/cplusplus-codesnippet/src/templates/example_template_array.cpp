#include <array> // c++11
#include <iostream>

int
main (int argc, char **argv)
{
  using namespace std;

  array<int, 5> arr_int;
  cout << arr_int.empty () << ", " << arr_int.size () << endl;

  array<double, 5> arr_double =
    { 1, 2, 3, 4 };
  cout << arr_double.empty () << ", " << arr_double.size () << endl;
  cout << arr_double[0] << ", " << arr_double[4] << endl;

  return 0;
}
