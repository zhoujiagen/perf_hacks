#include <iostream>
#include "brass.h"

int
main (int argc, char **argv)
{
  using namespace std;

  Brass Piggy ("Porcelot Pigg", 381299, 4000.00);
  BrassPlus Hoggy ("Horatio Hogg", 382288, 3000.00);
  Piggy.ViewAcct ();
  cout << endl;
  Hoggy.ViewAcct ();
  cout << endl;

  Hoggy.Deposit (1000.00);
  cout << "Hogg account balance: $" << Hoggy.Balance () << endl;
  Piggy.Withdraw (4200.00);
  cout << "Pigg account balance: $" << Piggy.Balance () << endl;
  Hoggy.Withdraw (4200.00);
  Hoggy.ViewAcct ();
  cout << endl;

  Brass *p_clients[4];
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
