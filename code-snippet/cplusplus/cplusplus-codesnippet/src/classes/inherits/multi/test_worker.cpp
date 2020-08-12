#include <iostream>
#include "worker.h"

using namespace std;

int
main (int argc, char **argv)
{
  Waiter bob ("Bob Apple", 314L, 5);
  Singer bev ("Beverly Hills", 522L, 3);
  Waiter waldo ("Waldo Dropmaster", 442L, 3);
  Singer sylvie ("Sylvie Serenne", 555L, 3);
  SingingWaiter natasha ("Natasha Gargalova", 1021L, 6, 3);

  Worker *pw[5] =
    { &bob, &bev, &waldo, &sylvie, &natasha };
  for (int i = 0; i < 5; i++)
    {
      pw[i]->Show ();
      cout << endl;
    }

  return 0;
}
