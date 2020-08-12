#include <iostream>

void
swapr (int &a, int &b);
void
swapp (int *p, int *q);
void
swapv (int a, int b);

struct free_throws
{
  std::string name;
  int made;
  int attempts;
  float percent;
};

void
display (const free_throws &ft);
void
set_pc (free_throws &ft);
free_throws&
accumulate (free_throws &target, const free_throws &source); // 注意: 返回值可能被重新赋值

int
main (int argc, char **argv)
{
  using namespace std;

  // 声明引用: 必须在声明时初始化
  int rats = 101;
  int &rodents = rats;
  cout << "rats: value=" << rats << ", address=" << &rats << endl;
  cout << "rodents: value=" << rodents << ", address=" << &rodents << endl;
  cout << endl;

  rodents++;
  cout << "rats: value=" << rats << ", address=" << &rats << endl;
  cout << "rodents: value=" << rodents << ", address=" << &rodents << endl;
  cout << endl;

  int bunnies = 50;
  rodents = bunnies;
  cout << "bunnies: value=" << bunnies << ", address=" << &bunnies << endl;
  cout << "rats: value=" << rats << ", address=" << &rats << endl;
  cout << "rodents: value=" << rodents << ", address=" << &rodents << endl;

  cout << endl;

  // 交换值
  int a = 100;
  int b = 200;
  cout << "a=" << a << ", b=" << b << endl;

  swapv (a, b); // 传递变量的值
  cout << "a=" << a << ", b=" << b << endl;

  a = 100;
  b = 200;
  swapr (a, b); // 传递变量
  cout << "a=" << a << ", b=" << b << endl;

  a = 100;
  b = 200;
  swapp (&a, &b); // 传递变量的地址
  cout << "a=" << a << ", b=" << b << endl;

  cout << endl;

  // 引用与结构体
  free_throws one =
    { "Ifelsa Branch", 13, 14 };
  free_throws two =
    { "Andor Knott", 10, 16 };
  free_throws three =
    { "Minnie Max", 7, 9 };
  free_throws four =
    { "Whily Looper", 5, 9 };
  free_throws five =
    { "Long Long", 6, 14 };
  free_throws team =
    { "Throwgoods", 0, 0 };

  free_throws dup;

  set_pc (one);
  display (one);
  accumulate (team, one);
  display (team);

  display (accumulate (team, two));
  accumulate (accumulate (team, three), four);
  display (team);

  dup = accumulate (team, five);
  display (team);
  display (dup);

  set_pc (four);

  // 引用与类对象

  return 0;
}

void
swapr (int &a, int &b)
{
  int temp;

  temp = a;
  a = b;
  b = temp;
}

void
swapp (int *p, int *q)
{
  int temp;

  temp = *p;
  *p = *q;
  *q = temp;
}

void
swapv (int a, int b)
{
  int temp;

  temp = a;
  a = b;
  b = temp;
}

void
display (const free_throws &ft)
{
  using namespace std;

  cout << "Name: " << ft.name << endl;
  cout << " Made=" << ft.made << ", Attempts=" << ft.attempts << ", Percent="
      << ft.percent << endl;

}
void
set_pc (free_throws &ft)
{
  if (ft.attempts != 0)
    {
      ft.percent = 100.0f * float (ft.made) / float (ft.attempts);
    }
  else
    {
      ft.percent = 0;
    }
}

free_throws&
accumulate (free_throws &target, const free_throws &source)
{
  target.attempts += source.attempts;
  target.made += source.made;
  set_pc (target);

  return target;
}
