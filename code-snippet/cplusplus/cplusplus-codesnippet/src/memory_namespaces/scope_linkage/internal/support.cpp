#include <iostream>

extern int tom; // 外部变量声明
static int dick = 10; // 覆盖外部的dick
int harry = 200; // 外部变量定义

void
remote_access ()
{
  using namespace std;

  cout << "In remote_access(), &tom=" << &tom << ", &dick=" << &dick
      << ", &harry=" << &harry << endl;
}
