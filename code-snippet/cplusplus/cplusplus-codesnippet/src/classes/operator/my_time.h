#ifndef SRC_CLASSES_OPERATOR_MY_TIME_H_
#define SRC_CLASSES_OPERATOR_MY_TIME_H_

#include <iostream>

class Time
{
private:
  int hours;
  int minutes;

public:
  Time ();

  Time (int h, int m = 0);

  void
  AddMin (int m);

  void
  AddHour (int h);

  void
  Reset (int h = 0, int m = 0);

  Time
  operator+ (const Time &t) const; // 运算符重载: +

  Time
  operator- (const Time &t) const;

  Time
  operator* (double n) const;

  friend Time
  operator* (double n, const Time &t); // 友元函数

//  void
//  Show () const;
  friend std::ostream&
  operator<< (std::ostream &os, const Time &t);
};

#endif /* SRC_CLASSES_OPERATOR_MY_TIME_H_ */
