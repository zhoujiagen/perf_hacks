#include <iostream>
#include "my_string.h"

void
func1 (MyString &ms);
void
func2 (MyString ms);

int
main (int argc, char **argv)
{
  using namespace std;

    {
      MyString headline1 ("Celery Stalks at Midnight");
      MyString headline2 ("Lettuce Prey");
      MyString sports ("Spinach Leaved Bowl for Dollars");
      cout << "headline1=" << headline1;
      cout << "headline2=" << headline2;
      cout << "sports=" << sports;
      cout << endl;

      func1 (headline1);
      cout << "headline1=" << headline1;
      cout << endl;

      func2 (headline2); // 传值: 调用复制构造函数
      cout << "headline2=" << headline2;
      cout << endl;

      MyString sailor = sports; // 调用复制构造函数
      cout << "sailor=" << sailor;
      cout << endl;

      MyString knot;
      knot = headline1; // 调用赋值运算符
      cout << "knot=" << knot;
      cout << endl;

      MyString *p_ms = new MyString ("hello");
      cout << "*p_ms=" << *p_ms;
      delete p_ms;
    }

  return 0;
}

void
func1 (MyString &ms)
{
  std::cout << "func1 (MyString &ms): " << ms;
}
void
func2 (MyString ms)
{
  std::cout << "func2 (MyString ms): " << ms;
}
