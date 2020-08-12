#include <iostream>

int
main (int argc, char **argv)
{
  short months[12] =
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
  std::cout << months << std::endl;
  std::cout << typeid(months).name () << std::endl;

  short months2[12]
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
  std::cout << months2 << std::endl;
  std::cout << sizeof(months2) << std::endl;

  return 0;
}

