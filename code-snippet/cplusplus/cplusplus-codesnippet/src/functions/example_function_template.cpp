#include <iostream>

// or class T
template<typename T>
  void
  Swap (T &a, T &b);

template void
Swap<char> (char&, char&); // 对char的显示实例化

template<typename T>
  void
  Swap (T *a, T *b, int n);

void
Show (int *a);
const int Lim = 8;

struct job
{
  char name[40];
  double salary;
  int floor;
};

// 函数模板的显式具体化(explicit specialization)
template<>
  void
  Swap<job> (job &j1, job &j2);
void
Show (job &j);

int
main (int argc, char **argv)
{
  using namespace std;

  int i = 10;
  int j = 20;
  cout << "i=" << i << ", j=" << j << endl;
  Swap (i, j);
  cout << "i=" << i << ", j=" << j << endl;

  double x = 24.5;
  double y = 81.7;
  cout << "x=" << x << ", y=" << y << endl;
  Swap (x, y);
  cout << "x=" << x << ", y=" << y << endl;

  // 函数模板重载
  int a[Lim] =
    { 0, 7, 0, 4, 1, 7, 7, 6 };
  int b[Lim] =
    { 0, 7, 2, 0, 1, 9, 9, 6 };
  Show (a);
  Show (b);
  Swap (a, b, Lim);
  Show (a);
  Show (b);

  // 显式具体化
  job sue =
    { "Susan Yaffee", 73000.60, 7 };
  job sidney =
    { "Sidney Taffee", 78060.72, 9 };
  Show (sue);
  Show (sidney);
  Swap (sue, sidney);
  Show (sue);
  Show (sidney);

  // 显式实例化
  char g = 'a';
  char h = 'b';
  cout << "g=" << g << ", h=" << h << endl;
  Swap (g, h);
  cout << "g=" << g << ", h=" << h << endl;

  return 0;
}

template<typename T>
  void
  Swap (T &a, T &b)
  {
    T temp;
    temp = a;
    a = b;
    b = temp;
  }

template<typename T>
  void
  Swap (T a[], T b[], int n)
  {
    T temp;

    for (int i = 0; i < n; i++)
      {
	temp = a[i];
	a[i] = b[i];
	b[i] = temp;
      }
  }

void
Show (int a[])
{

  for (int i = 0; i < Lim; i++)
    {
      std::cout << a[i];
    }
  std::cout << std::endl;
}

template<>
  void
  Swap<job> (job &j1, job &j2)
  {
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;

    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
  }

void
Show (job &j)
{
  using namespace std;

  cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}
