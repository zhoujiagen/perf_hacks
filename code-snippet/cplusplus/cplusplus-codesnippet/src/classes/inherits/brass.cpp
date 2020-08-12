#include <iostream>
#include "brass.h"

Brass::Brass (const string &s, long an, double bal)
{
  fullName = s;
  acctNum = an;
  balance = bal;
}
void
Brass::Deposit (double amt)
{
  if (amt < 0)
    return;
  else
    {
      balance += amt;
    }
}
void
Brass::Withdraw (double amt)
{
  if (amt < 0)
    return;
  else if (amt <= balance)
    {
      balance -= amt;
    }
  else
    {
      std::cout << "Withdraw amount exceeds balance." << std::endl;
    }
}
double
Brass::Balance () const
{
  return balance;
}
void
Brass::ViewAcct () const
{
  using namespace std;
  cout << "Client=" << fullName << ", AccNumber=" << acctNum << ", Balance="
      << balance;
}
Brass::~Brass ()
{
}

BrassPlus::BrassPlus (const string &s, long an, double bal, double ml, double r) :
    Brass (s, an, bal)
{
  maxLoan = ml;
  rate = r;
  owesBank = 0;
}
BrassPlus::BrassPlus (const Brass &b, double ml, double r) :
    Brass (b)
{
  maxLoan = ml;
  rate = r;
  owesBank = 0;
}
void
BrassPlus::ViewAcct () const
{
  using namespace std;

  Brass::ViewAcct ();
  cout << ", MaxLoan=" << maxLoan << ", OwesBank=" << owesBank << ", Rate="
      << rate;
}
void
BrassPlus::Withdraw (double amt)
{
//  double bal = Balance (); // balance
  if (amt <= balance)
    {
      Brass::Withdraw (amt);
    }
  else if (amt <= balance + maxLoan - owesBank)
    {
      double advance = amt - balance;
      owesBank += advance * (1.0 + rate);
      Deposit (advance);
      Brass::Withdraw (amt);
    }
  else
    {
      std::cout << "Credit limit exceed." << std::endl;
    }
}
