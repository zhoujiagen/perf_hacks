#include <iostream>
#include "stock.h"

int
main (int argc, char **argv)
{
  using namespace std;

  Stock s1 ("NanoSmart", 12, 20.0);
  s1.show ();

  Stock s2 = Stock ("Boffo Objects", 2, 2.0);
  s2.show ();

  s2 = s1; // 赋值
  s1.show ();
  s2.show ();

  s1 = Stock ("Nifty Foods", 10, 50.0); // 临时对象
  s1.show ();

  // C++11列表初始化
  Stock s3
    { "Sport Age Storage, Inc" };
  s3.show ();
  Stock s4 =
    { "Derivatives Plus Plus", 100, 45.0 };
  s4.show ();
  const Stock temp
    { };
  temp.show ();

  // 动态对象
  Stock *s5 = new Stock ("Noodle", 13, 2.50);
  s5->show ();
  delete s5;

  cout << endl;

  // 对象数组
  Stock stocks[5] =
    { Stock ("NanoSmart", 12, 20.0), //
    Stock ("Boffo Objects", 200, 2.0), //
    Stock ("Monolithic Obelisks", 130, 3.25), //
    Stock ("Fleep Enterprises", 60, 6.5) };
  int i;
  for (i = 0; i < 5; i++)
    {
      stocks[i].show ();
    }
  const Stock *top = &stocks[0];
  for (i = 1; i < 5; i++)
    {
      top = &top->topval (stocks[i]);
    }
  top->show ();

  return 0;
}
