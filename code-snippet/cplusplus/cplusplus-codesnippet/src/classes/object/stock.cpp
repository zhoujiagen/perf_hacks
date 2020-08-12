#include <iostream>
#include "stock.h"

Stock::Stock ()
{
  std::cout << "Stock()" << std::endl;

  company = "no name";
  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}

Stock::Stock (const std::string &co, long n, double pr)
{
  std::cout << "Stock(" << co << "...)" << std::endl;

  company = co;
  if (n < 0)
    shares = 0;
  else
    shares = n;
  share_val = pr;
  set_total ();
}

Stock::~Stock ()
{
  std::cout << "~Stock(" << company << "...)" << std::endl;
}

void
Stock::buy (long num, double price)
{
  if (num < 0)
    {
      return;
    }
  else
    {
      shares += num;
      share_val = price;
      set_total ();
    }
}

void
Stock::sell (long num, double price)
{
  if (num < 0)
    {
      return;
    }
  else if (num > shares)
    {
      return;
    }
  else
    {
      shares -= num;
      share_val = price;
      set_total ();
    }
}

void
Stock::update (double price)
{
  share_val = price;
  set_total ();
}

void
Stock::show () const
{
  using namespace std;

  cout << "Company=" << company << ", Shares=" << shares << ", Price=$"
      << share_val << ", Total=$" << total_val << endl;
}

const Stock&
Stock::topval (const Stock &s) const
{
  if (s.total_val > total_val)
    return s;
  else
    return *this; // this指针
}
