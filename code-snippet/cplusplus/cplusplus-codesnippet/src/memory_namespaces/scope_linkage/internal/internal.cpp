#include <iostream>

int tom = 3;	// 外部变量定义
int dick = 30; // 外部变量定义
static int harry = 300; // 静态, 内部链接性

void
remote_access ();

int
main (int argc, char **argv)
{
  using namespace std;

  cout << "In main(), &tom=" << &tom << ", &dick=" << &dick << ", &harry="
      << &harry << endl;

  remote_access ();

  return 0;
}

