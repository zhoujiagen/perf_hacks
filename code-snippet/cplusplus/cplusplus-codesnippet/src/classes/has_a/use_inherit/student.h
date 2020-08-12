#ifndef SRC_CLASSES_HAS_A_USE_INHERIT_STUDENT_H_
#define SRC_CLASSES_HAS_A_USE_INHERIT_STUDENT_H_

#include <iostream>
#include<string>
#include <valarray>

using std::string;
using std::valarray;
using std::ostream;

// 私有继承
//class Student : private string, private valarray<double>
// 保护继承
class Student : protected string, protected valarray<double>
{
private:
  typedef valarray<double> ArrayDb;
  ostream&
  arr_out (ostream &os) const;

public:
  Student () :
      string ("Null Student"), ArrayDb ()
  {
  }

  explicit
  Student (const string &s) :
      string (s), ArrayDb ()
  {
  }

  Student (const string &s, int n) :
      string (s), ArrayDb (n)
  {
  }

  Student (const string &s, const ArrayDb &a) :
      string (s), ArrayDb (a)
  {
  }

  Student (const char *str, const double *pd, int n) :
      string (str), ArrayDb (pd, n)
  {
  }

  ~Student ()
  {
  }

  double
  Average () const;
  double&
  operator[] (int i);
  double
  operator[] (int i) const;
  const string&
  Name () const;

  friend ostream&
  operator<< (ostream &os, const Student &stu);
};

#endif /* SRC_CLASSES_HAS_A_USE_INHERIT_STUDENT_H_ */
