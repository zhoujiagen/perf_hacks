#include <iostream>

// 函数原型
void
simple ();

int
bigger (int, int);

int
main (int argc, char **argv)
{
  using namespace std;
  cout << "main() will call the simple() function" << endl;
  simple (); // 函数调用
  cout << "main() is finished with the simple() function" << endl;

  return 0;
}

// 函数定义
void
simple ()
{
  using namespace std;

  cout << "I'm but a simple function" << endl;
}

int
bigger (int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}

