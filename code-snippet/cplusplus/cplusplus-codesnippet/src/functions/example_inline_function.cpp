#include <iostream>

// 内联函数
inline double
square (double x)
{
  return x * x;
}

int
main (int argc, char **argv)
{
  using namespace std;

  double a = square (4.0);
  double b = square (5.0);
  cout << "a=" << a << ", b=" << b << endl;

  return 0;
}
