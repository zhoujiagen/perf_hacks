#ifndef SRC_CLASSES_HAS_A_CONTAINMENT_STUDENT_H_
#define SRC_CLASSES_HAS_A_CONTAINMENT_STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>

using std::string;
using std::valarray;

class Student
{
private:
  typedef valarray<double> ArrayDb;
  string name;
  ArrayDb scores;
  std::ostream&
  arr_out (std::ostream &os) const;

public:
  Student () :
      name ("Null Student"), scores ()
  {
  }
  explicit
  Student (const string &s) :
      name (s), scores ()
  {
  }
  explicit
  Student (int n) :
      name ("Nully"), scores (n)
  {
  }
  Student (const string &s, int n) :
      name (s), scores (n)
  {
  }
  Student (const string &s, const ArrayDb &a) :
      name (s), scores (a)
  {
  }
  Student (const char *str, const double *pd, int n) :
      name (str), scores (pd, n)
  {
  }
  ~Student ()
  {
  }

  double
  Average () const;
  const string&
  Name () const;
  double&
  operator[] (int i);
  double
  operator[] (int i) const;

  friend std::ostream&
  operator<< (std::ostream &os, const Student &stu);
};

#endif /* SRC_CLASSES_HAS_A_CONTAINMENT_STUDENT_H_ */
