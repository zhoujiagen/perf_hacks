#include <iostream>

long double
probability (unsigned, unsigned);

int
main (int argc, char **argv)
{

  using namespace std;

  unsigned numbers = 49;
  unsigned picks = 6;
  cout << probability (numbers, picks) << endl;

  return 0;
}

// 两个参数
long double
probability (unsigned numbers, unsigned picks)
{
  long double result = 1.0;

  long double n;
  unsigned p;

  for (n = numbers, p = picks; p > 0; p--)
    {
      result = result * n / p;
    }

  return result;
}

