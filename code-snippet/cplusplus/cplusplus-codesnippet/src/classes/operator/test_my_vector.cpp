#include <iostream>
#include "my_vector.h"

int
main (int argc, char **argv)
{
  using namespace std;
  using namespace VECTOR;

  Vector folly (3.0, 4.0);
  cout << folly;
  folly.polar_mode ();
  cout << folly;
  folly.rect_mode ();
  cout << folly;

  Vector foolery (20.0, 30.0, VECTOR::Vector::POL);
  cout << foolery;
  cout << foolery * 2;

  return 0;
}
