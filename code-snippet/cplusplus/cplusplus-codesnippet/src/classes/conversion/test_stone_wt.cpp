#include <iostream>
#include "stone_wt.h"

int
main (int argc, char **argv)
{
  using namespace std;

  StoneWT mycat;
  mycat = 19.6;
  mycat.show_lbs ();
  cout << endl;

  mycat = StoneWT (19.6);
  mycat.show_lbs ();
  cout << endl;

  mycat = (StoneWT) 19.6;
  mycat.show_lbs ();
  cout << endl;

  double d_mycat = (double) mycat;
  cout << "d_mycat=" << d_mycat << endl;
  int i_mycat = int (mycat);
  cout << "i_mycat=" << i_mycat << endl;

  return 0;
}
