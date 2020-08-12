#include <iostream>
#include "acct_abc.h"

int
main (int argc, char **argv)
{
  using namespace std;

  AcctABC *p_clients[4];
  p_clients[0] = new Brass ("Harry Fishsong", 112233, 1500.00);
  p_clients[1] = new BrassPlus ("Dinah Otternoe", 121213, 1800.00, 350.00,
				0.12);
  p_clients[2] = new BrassPlus ("Brenda Bierherd", 122118, 5200, 800.00, 0.10);
  p_clients[3] = new Brass ("Tim Turtletop", 233255, 688);

  for (int i = 0; i < 4; i++)
    {
      p_clients[i]->ViewAcct ();
      cout << endl;
    }

  for (int i = 0; i < 4; i++)
    {
      delete p_clients[i];
    }

  return 0;
}
