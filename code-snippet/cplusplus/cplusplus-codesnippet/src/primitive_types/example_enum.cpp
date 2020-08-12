#include <iostream>

enum spectrum
{
  red, orange, yellow, green, blue, violet, indigo, ultraviolet
};

// 只使用常量
enum
{
  RED, GREEN, BLUE
};

// 显式的设置枚举量的值
enum bits
{
  one = 1, two = 2, four = 4, eight = 8
};

// 允许有多个值相同的枚举量
enum
{
  zero, null = 0, one, numero_uno = 1
};

int
main (int argc, char **argv)
{
  using namespace std;

  spectrum band;
  band = blue;
  cout << "band=" << band << endl;
  band = spectrum (3);
  cout << "band=" << band << endl;
  int color = blue;
  cout << "color=" << color << endl;

  return 0;
}
