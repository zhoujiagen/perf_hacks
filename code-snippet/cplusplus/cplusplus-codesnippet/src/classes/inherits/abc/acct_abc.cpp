#include <iostream>
#include "acct_abc.h"

using std::cout;
using std::endl;
using std::string;

AcctABC::AcctABC (const string &s, long an, double bal)
{
  fullName = s;
  acctNum = an;
  balance = bal;
}

void
AcctABC::Deposit (double amt)
{
  if (amt < 0)
    return;
  else
    balance += amt;
}

void
AcctABC::Withdraw (double amt)
{
  balance -= amt;
}

void
Brass::Withdraw (double amt)
{
  if (amt < 0)
    return;
  else if (amt <= Balance ())
    AcctABC::Withdraw (amt);
  else
    cout << "exceed balance." << endl;
}

void
Brass::ViewAcct () const
{
  cout << "Brass Client=" << FullName () << ", AccNumber=" << AcctNum ()
      << ", Balance=" << Balance ();
}

BrassPlus::BrassPlus (const string &s, long an, double bal, double ml, double r) :
    AcctABC (s, an, bal)
{
  maxLoan = ml;
  rate = r;
  owesBank = 0.0;
}

BrassPlus::BrassPlus (const Brass &ba, double ml, double r) :
    AcctABC (ba)
{
  maxLoan = ml;
  rate = r;
  owesBank = 0.0;
}

void
BrassPlus::ViewAcct () const
{
  cout << "BrassPlus Client=" << FullName () << ", AccNumber=" << AcctNum ()
      << ", Balance=" << Balance ();
  cout << ", MaxLoan=" << maxLoan << ", OwesBank=" << owesBank << ", Rate="
      << rate;
}

void
BrassPlus::Withdraw (double amt)
{
  double bal = Balance ();
  if (amt <= bal)
    {
      AcctABC::Withdraw (amt);
    }
  else if (amt <= bal + maxLoan - owesBank)
    {
      double advance = amt - bal;
      owesBank += advance * (1.0 + rate);
      Deposit (advance);
      AcctABC::Withdraw (amt);
    }
  else
    {
      std::cout << "Credit limit exceed." << std::endl;
    }
}
