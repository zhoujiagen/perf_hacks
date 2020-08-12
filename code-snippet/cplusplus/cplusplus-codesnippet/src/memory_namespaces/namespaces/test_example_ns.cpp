#include <iostream>
#include "example_ns.h"

void
other (void);

int
main (int argc, char **argv)
{
  using debts::Debt;
  using debts::showDebt;

  Debt golf =
    {
      { "Benny", "Goatsniff" }, 120.0 };
  showDebt (golf);

  other ();

  return 0;
}

void
other ()
{
  using std::cout;
  using std::endl;

  using pers::Person;
  Person collector =
    { "Milo", "Rightshift" };
  pers::showPerson (collector);
  cout << endl;
}
