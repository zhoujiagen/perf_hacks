#include <iostream>
#include "my_time.h"

Time::Time ()
{
  hours = minutes = 0;
}

Time::Time (int h, int m)
{
  hours = h;
  minutes = m;
}

void
Time::AddMin (int m)
{
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void
Time::AddHour (int h)
{
  hours += h;
}

void
Time::Reset (int h, int m)
{
  hours = h;
  minutes = m;
}

Time
Time::operator+ (const Time &t) const
{
  Time result;

  result.minutes = minutes + t.minutes;
  result.hours = hours + t.hours + result.minutes / 60;
  result.minutes %= 60;
  return result;
}

Time
Time::operator- (const Time &t) const
{
  Time result;
  int total1 = t.minutes + 60 * t.hours;
  int total2 = minutes + 60 * hours;
  result.minutes = (total2 - total1) % 60;
  result.hours = (total2 - total1) / 60;
  return result;
}

Time
Time::operator* (double n) const
{
  Time result;
  long total = hours * 60 * n + minutes * n;
  result.minutes = total % 60;
  result.hours = total / 60;
  return result;
}

Time
operator* (double n, const Time &t)
{
//  Time result;
//  long total = t.hours * 60 * n + t.minutes * n;
//  result.minutes = total % 60;
//  result.hours = total / 60;
//  return result;
  return t * n;
}

//void
//Time::Show () const
//{
//  using namespace std;
//
//  cout << hours << " hours, " << minutes << " minutes" << endl;
//}

std::ostream&
operator<< (std::ostream &os, const Time &t)
{
  os << t.hours << " hours, " << t.minutes << " minutes" << std::endl;
  return os;
}
