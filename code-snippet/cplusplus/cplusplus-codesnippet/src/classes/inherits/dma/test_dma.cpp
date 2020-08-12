#include <iostream>
#include "dma.h"

using std::cout;
using std::endl;

int
main (int argc, char **argv)
{
  baseDMA shirt ("Portabelly", 8);
  lacksDMA balloon ("red", "Blimpo", 4);
  hasDMA map ("Mercator", "Buffalo Keys", 5);
  cout << shirt << endl;
  cout << balloon << endl;
  cout << map << endl;

  lacksDMA balloon2 (balloon); // 调用默认拷贝构造函数
  cout << balloon2 << endl;
  hasDMA map2;
  map2 = map;  // 调用赋值运算符
  cout << map2 << endl;

  return 0;
}
