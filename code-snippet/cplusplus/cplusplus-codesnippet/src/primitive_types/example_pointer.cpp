#include <iostream>

int
main (int argc, char **argv)
{
  using namespace std;

  int n_int = 6;
  double n_double = 2.3;

  cout << "n_int=" << n_int << ", &n_int=" << &n_int << endl;
  cout << "n_double=" << n_double << ", &n_double=" << &n_double << endl;

  int *p_int;
  p_int = &n_int;
  cout << "p_int=" << p_int << ", *p_int=" << *p_int << endl;
  *p_int = *p_int + 1;
  cout << "p_int=" << p_int << ", *p_int=" << *p_int << endl;
  cout << endl;

  // memory management: new, delete

  int *p_n = new int;
  *p_n = 100;
  cout << "p_n=" << p_n << ", *p_n=" << *p_n << endl;
  cout << "sizeof(p_n)=" << sizeof(p_n) << endl; // 8
  delete p_n;

  int *p_array = new int[10];
  cout << "sizeof(p_array)=" << sizeof(p_array) << endl; // 8
  delete[] p_array;

  int arr_int[]
    { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  cout << "sizeof(arr_int)=" << sizeof(arr_int) << endl; // 40
  cout << endl;

  // const变量
  // 将非const变量的地址 赋给 指向const的指针
  int age = 33;
  const int *pt = &age; 	// a pointer to const int
  // 将const变量的地址 赋给 指向const的指针
  const float g_earth = 9.80;
  const float *pe = &g_earth;
  // 将const变量的地址 赋给 指向非const的指针
  const float g_moon = 1.63;
//  float *pm = &g_moon; 	// ERROR
  float *pm = const_cast<float*> (&g_moon); // a pointer to float
  // 指向指针的指针
  const int **pp; 		// a pointer to a pointer to const int
  int *p = &age; 		// a pointer to int
  const int n = 13;
  *pp = &n;
//  pp = &p; 			// ERROR: assigning to 'const int **' from incompatible type 'int **'
  *p = 10;

  // const指针
  int sloth = 3;
  const int *ps = &sloth; 	// a pointer to const int
  int *const finger = &sloth; 	// a const pointer to int
//  *ps = 4;			// ERROR
  ps = &age;
  *finger = 4;
//  finger = &age;		// ERROR

  double trouble = 2.0E30;
  const double *const stick = &trouble;

  return 0;
}
