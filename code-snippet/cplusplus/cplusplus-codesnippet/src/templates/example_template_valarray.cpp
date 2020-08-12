#include <iostream>
#include <valarray>

int
main (int argc, char **argv)
{

  using namespace std;

  // 数值数组
  double gpa[5] =
    { 3.1, 3.5, 3.8, 2.9, 3.3 };
  valarray<double> v1; // size: 0
  cout << v1.size () << endl;

  valarray<int> v2 (8); // size: 8
  cout << v2.size () << endl;

  valarray<int> v3 (10, 8); // size: 8, e: 10
  cout << v3.size () << endl;

  valarray<double> v4 (gpa, 4); // size: 4, e: first 4 elements of gpa
  cout << v4.size () << endl;

  valarray<int> v5 =
    { 20, 32, 17, 9 }; // C++11
  cout << v5.size () << endl;

  return 0;
}
