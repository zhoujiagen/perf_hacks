#ifndef SRC_CLASSES_ABC_ACCT_ABC_H_
#define SRC_CLASSES_ABC_ACCT_ABC_H_

#include <string>
using std::string;

class AcctABC
{
private:
  string fullName;
  long acctNum;
  double balance;
protected:
  const string&
  FullName () const
  {
    return fullName;
  }
  long
  AcctNum () const
  {
    return acctNum;
  }
public:
  AcctABC (const string &s = "Nullbody", long an = -1, double bal = 0.0);
  void
  Deposit (double amt);
  virtual void
  Withdraw (double amt) = 0; // 纯虚函数
  double
  Balance () const
  {
    return balance;
  }
  virtual void
  ViewAcct () const = 0; // 纯虚函数
  virtual
  ~AcctABC ()
  {
  }
};

class Brass : public AcctABC
{
public:
  Brass (const string &s = "Nullbody", long an = -1, double bal = 0.0) :
      AcctABC (s, an, bal)
  {
  }
  virtual void
  Withdraw (double amt);
  virtual void
  ViewAcct () const;
  virtual
  ~Brass ()
  {
  }
};

class BrassPlus : public AcctABC
{
private:
  double maxLoan;
  double rate;
  double owesBank;
public:
  BrassPlus (const string &s = "Nullbody", long an = -1, double bal = 0.0,
	     double ml = 500, double r = 0.10);
  BrassPlus (const Brass &ba, double ml = 500, double r = 0.10);
  virtual void
  ViewAcct () const;
  virtual void
  Withdraw (double amt);
  void
  ResetMax (double m)
  {
    maxLoan = m;
  }
  void
  ResetRate (double r)
  {
    rate = r;
  }
  void
  ResetOwes ()
  {
    owesBank = 0;
  }
};

#endif /* SRC_CLASSES_ABC_ACCT_ABC_H_ */
