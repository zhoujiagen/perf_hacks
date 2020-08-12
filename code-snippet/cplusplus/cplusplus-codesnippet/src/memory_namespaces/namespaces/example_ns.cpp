#include <iostream>
#include "example_ns.h"

namespace pers
{
  using std::cout;

  void
  getPerson (Person &rp)
  {
    rp.fname = "fname";
    rp.lname = "lname";
  }

  void
  showPerson (const Person &rp)
  {
    cout << rp.lname << ", " << rp.fname;
  }
}

namespace debts
{
  using namespace pers;

  void
  getDebt (Debt &rd)
  {
    getPerson (rd.name);
    rd.amount = 1.0;
  }

  void
  showDebt (const Debt &rd)
  {
    showPerson (rd.name);
    std::cout << ": $" << rd.amount << std::endl;
  }

  double
  sumDebts (const Debt ar[], int n)
  {
    double total = 0;
    for (int i = 0; i < n; i++)
      {
	total += ar[i].amount;
      }
    return total;
  }
}
