#include <iostream>

extern double warming; // 外部变量, 引用声明

// 函数原型

void
update (double dt);

void
local ();

// 函数定义

void
update (double dt)
{
  using namespace std;

  extern double warming;
  warming += dt;

  cout << "Update warming to " << warming << endl;
}

void
local ()
{
  using namespace std;

  double warming = 0.8;

  cout << "Local warming=" << warming;
  cout << ", But global warming=" << ::warming << endl;

}
