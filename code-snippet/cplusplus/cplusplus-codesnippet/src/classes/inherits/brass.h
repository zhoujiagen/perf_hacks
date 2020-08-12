#ifndef SRC_CLASSES_INHERITS_BRASS_H_
#define SRC_CLASSES_INHERITS_BRASS_H_

#include <string>
using std::string;

// Brass account
class Brass
{
private:
  string fullName;
  long acctNum;
protected: // protected字段
  double balance;
public:
  Brass (const string &s = "Nullbody", long an = -1, double bal = 0.0);
  void
  Deposit (double amt); // 存款
  // 虚函数: 动态绑定
  virtual void
  Withdraw (double amt); // 取款
  double
  Balance () const;
  virtual void
  ViewAcct () const;
  virtual
  ~Brass ();
};

// Brass plus account
class BrassPlus : public Brass
{
private:
  double maxLoan;
  double rate;
  double owesBank;

public:
  BrassPlus (const string &s = "Nullbody", long an = -1, double bal = 0.0,
	     double ml = 500, double r = 0.11125);
  BrassPlus (const Brass &b, double ml = 500, double r = 0.11125);
  virtual void
  ViewAcct () const;
  virtual void
  Withdraw (double amt);
  void
  RestMaxLoan (double m)
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

#endif /* SRC_CLASSES_INHERITS_BRASS_H_ */
