#include <iostream>
#include <cmath>

void
oil (int x);

int global = 1000; // 静态存储, 外部链接性
static int one_file = 50; // 静态存续, 内部链接性

int static_1;	// 静态变量: 零初始化
int static_2 = 5; // 静态变量: 常量表达式初始化
int static_3 = 13 * 13; // 静态变量: 常量表达式初始化
const double pi = 4.0 * std::atan (1.0); //静态变量: 动态初始化

int
main (int argc, char **argv)
{
  using namespace std;

  // 自动变量
  int texas = 31;
  int year = 2011;
  cout << "In main(), texas=" << texas << ", &texas=" << &texas << endl;
  cout << "In main(), year=" << year << ", &year=" << &year << endl;

  oil (texas);

  cout << "In main(), texas=" << texas << ", &texas=" << &texas << endl;
  cout << "In main(), year=" << year << ", &year=" << &year << endl;

  // 静态变量
  cout << "global=" << global << endl;
  cout << "one_file=" << one_file << endl;
  cout << "static_1=" << static_1 << endl;
  cout << "static_2=" << static_2 << endl;
  cout << "static_3=" << static_3 << endl;
  cout << "pi=" << pi << endl;

  return 0;
}

void
oil (int x)
{
  using namespace std;

  int texas = 5;
  cout << "In oil(), texas=" << texas << ", &texas=" << &texas << endl;
  cout << "In oil(), x=" << x << ", &x=" << &x << endl;

    { // 代码块
      int texas = 113;
      cout << "In block, texas=" << texas << ", &texas=" << &texas << endl;
      cout << "In block, x=" << x << ", &x=" << &x << endl;
    }

  cout << "Post block, texas=" << texas << ", &texas=" << &texas << endl;
}

void
funct1 (int n)
{
  static int count = 0; // 静态存储, 无链接性
}
