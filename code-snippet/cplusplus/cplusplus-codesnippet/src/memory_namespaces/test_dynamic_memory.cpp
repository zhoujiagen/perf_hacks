#include <iostream>

int
main (int argc, char **argv)
{
  using namespace std;

  int *pi = new int
    { 6 };
  double *pd = new double
    { 99.99 };
  int *pa = new int[40];

  cout << "pi: address=" << pi << ", value=" << *pi << endl;
  cout << "pd: address=" << pd << ", value=" << *pd << endl;
  cout << "pa: address=" << pa << endl;

  delete pi;
  delete pd;
  delete[] pa;

  return 0;
}
