#ifndef SRC_CLASSES_ALLOCATION_MY_STRING_H_
#define SRC_CLASSES_ALLOCATION_MY_STRING_H_

#include <iostream>

class MyString
{
private:
  char *str;
  int len;
  static int num_strings;
public:
  MyString ();
  MyString (const char *s);
  MyString (const MyString &ms); // 复制构造函数

  MyString&
  operator= (const MyString &ms); // 赋值运算符
  MyString&
  operator= (const char *s);

  ~MyString ();

  int
  length () const
  {
    return len;
  }

  friend std::ostream&
  operator<< (std::ostream &os, const MyString &ms);
  friend bool
  operator< (const MyString &ms1, const MyString &ms2);
  friend bool
  operator> (const MyString &ms1, const MyString &ms2);
  friend bool
  operator== (const MyString &ms1, const MyString &ms2);
  char
  operator[] (int i);
  const char&
  operator[] (int i) const;
  static int
  HowMany ();
};

#endif /* SRC_CLASSES_ALLOCATION_MY_STRING_H_ */
