#include <iostream>

using namespace std;
double warming = 0.3; // 外部变量, 定义

// 函数原型
void
update (double dt);
void
local ();

int
main (int argc, char **argv)
{
  cout << "Global warming=" << warming << endl;

  update (0.1);
  cout << "Global warming=" << warming << endl;

  local ();
  cout << "Global warming=" << warming << endl;

  return 0;
}

