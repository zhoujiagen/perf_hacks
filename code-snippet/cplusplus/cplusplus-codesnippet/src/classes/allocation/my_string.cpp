#include <iostream>
#include <cstring>
#include "my_string.h"

int MyString::num_strings = 0;

MyString::MyString ()
{
  std::cout << "MyString ()" << std::endl;

  len = 0;
  str = new char[1];
  str[0] = '\0';
  num_strings++;
}

MyString::MyString (const char *s)
{
  std::cout << "MyString (const char *s): " << s << std::endl;

  len = std::strlen (s); // C风格字符串的长度
  str = new char[len + 1];
  std::strcpy (str, s);
  num_strings++;
}

MyString::MyString (const MyString &ms)
{
  std::cout << "MyString (const MyString &s): " << ms << std::endl;

  num_strings++;
  len = ms.len;
  str = new char[len + 1];
  std::strcpy (str, ms.str);
}

MyString&
MyString::operator= (const MyString &ms)
{
  std::cout << "operator= (const MyString &ms): " << ms << std::endl;

  if (this == &ms)
    return *this;

  delete[] str; // 删除旧的字符串
  len = ms.len;
  str = new char[len + 1];
  std::strcpy (str, ms.str);
  return *this;
}

MyString&
MyString::operator= (const char *s)
{
  std::cout << "operator= (const char *s): " << s << std::endl;

  delete[] str;
  len = std::strlen (s);
  str = new char[len + 1];
  std::strcpy (str, s);
  return *this;
}

MyString::~MyString ()
{
  std::cout << "~MyString (): " << str << std::endl;

  --num_strings;
  delete[] str;
}

std::ostream&
operator<< (std::ostream &os, const MyString &ms)
{
  os << ms.str << std::endl;
  return os;
}

bool
operator< (const MyString &ms1, const MyString &ms2)
{
  return (std::strcmp (ms1.str, ms2.str) < 0);
}

bool
operator> (const MyString &ms1, const MyString &ms2)
{
  return ms2 < ms1;
}
bool
operator== (const MyString &ms1, const MyString &ms2)
{
  return (std::strcmp (ms1.str, ms2.str) == 0);
}

char
MyString::operator[] (int i)
{
  return str[i];
}

const char&
MyString::operator[] (int i) const
{
  return str[i];
}

int
MyString::HowMany ()
{
  return num_strings;
}
