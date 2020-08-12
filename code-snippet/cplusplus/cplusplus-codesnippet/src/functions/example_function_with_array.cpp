#include <iostream>
#include <array>

static const int ArraySize = 8;

int
sum (const int[], int);

//int
//sum2 (const int[][4], int);
//int
//sum2 (const int (*arr)[4], int);
int
sum2 (const int (*)[4], int);

const int Seasons = 4;

const std::array<std::string, Seasons> SeasonNames =
  { "Spring", "Summer", "Fall", "Winter" };

void
show (std::array<double, Seasons> da);

int
main (int argc, char **argv)
{

  using namespace std;

  cout << "sizeof int=" << sizeof(int) << endl; 		// 4
  cout << "sizeof pointer=" << sizeof(int*) << endl; 		// 8

  // 数组
  int cookies[ArraySize]
    { 1, 2, 4, 8, 16, 32, 64, 128 };
  cout << "address of cookies=" << cookies;
  cout << ", sizeof cookies=" << sizeof(cookies) << endl; 	// 32 = 8 * 4
  cout << sum (cookies, ArraySize) << endl;

  // 二维数组
  int data[][4] =
    {
      { 1, 2, 3, 4 },
      { 9, 8, 7, 6 },
      { 2, 4, 6, 8 } };
  cout << "sizeof data=" << sizeof data << endl; // 48 = row 3 * column 4 * 4 int
  cout << "data=" << data << endl; // pointer to first row of an array of 4 int
  cout << "data + 1=" << data + 1 << endl; // pointer to row 1
  cout << "*(data + 1)=" << *(data + 1) << endl; // row 1: pointer to the first int in row 1
  cout << "*(data + 1) + 2=" << *(data + 1) + 2 << endl; // pointer to column 2 in row 1
  cout << "*(*(data + 1) + 2)=" << *(*(data + 1) + 2) << endl; // value of column 2 in row 1
  cout << sum2 (data, 3) << endl;

  char ghost[15] = "galloping";
//  char *str = "galloping"; // ISO C++11 does not allow conversion from string literal to 'char *'
  const char *str = static_cast<const char*> ("galloping");
  int n1 = strlen (ghost);
  int n2 = strlen (str);
  int n3 = strlen ("galloping");
  cout << "n1=" << n1 << endl;
  cout << "n2=" << n2 << endl;
  cout << "n3=" << n3 << endl;

  // array
  array<double, Seasons> expenses =
    { 1.0, 2.0, 3.0, 4.0 };
  show (expenses);

  return 0;
}

// 数组作为参数
int
sum (const int arr[], int n)
{
  std::cout << "address of arr=" << arr;
  // sizeof arr等价于sizeof((int *) arr)
  std::cout << ", sizeof arr=" << sizeof((int*) arr) << std::endl;

  int total = 0;

  for (int i = 0; i < n; i++)
    {
      total += arr[i];
    }

  return total;
}

// 二维数组作为参数
int
sum2 (const int arr[][4], int size)
{
  int total = 0;

  for (int r = 0; r < size; r++)
    for (int c = 0; c < 4; c++)
      total += arr[r][c];

  return total;
}

void
show (std::array<double, Seasons> da)
{
  for (int i = 0; i < Seasons; i++)
    {
      std::cout << SeasonNames[i] << ": $" << da[i] << std::endl;
    }
}

