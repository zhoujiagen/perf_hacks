#include <iostream>
#include "my_time.h"

int
main (int argc, char **argv)
{
  using namespace std;

  Time planning;
  Time coding (2, 40);
  Time fixing (5, 55);
  Time total;

//  planning.Show ();
  cout << planning;
//  coding.Show ();
  cout << coding;
//  fixing.Show ();
  cout << fixing;

  total = coding + fixing;
//  total.Show ();
  cout << total;

  Time weeding (4, 35);
  Time waxing (2, 47);
  Time diff = weeding - waxing;
//  diff.Show ();
  cout << diff;
  total = weeding + waxing;
  Time adjusted = total * 1.5;
//  adjusted.Show ();
  cout << adjusted;
  adjusted = 1.5 * total;
//  adjusted.Show ();
  cout << adjusted;

  return 0;
}
