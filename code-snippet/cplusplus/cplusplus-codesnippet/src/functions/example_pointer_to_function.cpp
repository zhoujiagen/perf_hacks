#include <iostream>

double
betsy (int);
double
pam (int);

void
estimate (int lines, double
(*pf) (int));

const double*
f1 (const double ar[], int n);
const double*
f2 (const double[], int n);
const double*
f3 (const double*, int n);

typedef const double*
(*p_fun) (const double*, int);

int
main (int argc, char **argv)
{

  using namespace std;

  int code = 30;
  estimate (code, betsy);

  code = 100;
  estimate (code, pam);

  double av[3] =
    { 1112.3, 1542.6, 2227.9 };
  p_fun p1 = f1;
  auto p2 = f2;
  p_fun pa[3] =
    { f1, f2, f3 };
  cout << (*p1) (av, 3) << ": " << *(*p1) (av, 3) << endl;
  cout << p2 (av, 3) << ": " << *p2 (av, 3) << endl;
  cout << *pa[2] (av, 3) << endl;

  return 0;
}

double
betsy (int lns)
{
  return 0.05 * lns;
}
double
pam (int lns)
{
  return 0.03 * lns + 0.0004 * lns * lns;
}

void
estimate (int lines, double
(*pf) (int))
{
  using namespace std;

  cout << lines << " lines will take ";
  cout << (*pf) (lines) << " hours" << endl;
}

const double*
f1 (const double *ar, int n)
{
  return ar;
}

const double*
f2 (const double ar[], int n)
{
  return ar + 1;
}

const double*
f3 (const double ar[], int n)
{
  return ar + 2;
}
