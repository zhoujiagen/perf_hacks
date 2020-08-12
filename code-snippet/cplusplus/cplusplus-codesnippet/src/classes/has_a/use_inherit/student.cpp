#include "student.h"

ostream&
Student::arr_out (ostream &os) const
{
  int i;
  int lim = ArrayDb::size ();
  if (lim > 0)
    {
      for (i = 0; i < lim; i++)
	{
	  os << ArrayDb::operator[] (i) << " ";
	  if (i % 5 == 4)
	    os << std::endl;
	}
      if (i % 5 != 0)
	os << std::endl;
    }
  else
    os << " empty array";

  return os;
}

double
Student::Average () const
{
  // 私有继承 使用类型和作用域解析运算符来调用基类的方法
  if (ArrayDb::size () > 0)
    return ArrayDb::sum () / ArrayDb::size ();
  else
    return 0;
}

double&
Student::operator[] (int i)
{
  return ArrayDb::operator[] (i);
}

double
Student::operator[] (int i) const
{
  return ArrayDb::operator[] (i);
}

const string&
Student::Name () const
{
  // 使用强制类型转换
  return (const string&) *this;
}

ostream&
operator<< (ostream &os, const Student &stu)
{
  os << "Scores for " << (const string&) stu << ":\n";
  stu.arr_out (os);

  return os;
}
