#ifndef SRC_CLASSES_INHERITS_DMA_H_
#define SRC_CLASSES_INHERITS_DMA_H_

#include <iostream>

class baseDMA
{
private:
  char *label;
  int rating;
public:
  baseDMA (const char *l = "null", int r = 0);
  baseDMA (const baseDMA &rs);
  virtual
  ~baseDMA ();
  baseDMA&
  operator= (const baseDMA &rs);
  friend std::ostream&
  operator<< (std::ostream &os, const baseDMA &rs);
};

// derived class without DMA
// 不需要显式定义析构函数/拷贝构造函数/赋值运算符
class lacksDMA : public baseDMA
{
private:
  static const int COL_LEN = 40;
  char color[COL_LEN];
public:
  lacksDMA (const char *c = "blank", const char *l = "null", int r = 0);
  lacksDMA (const char *c, const baseDMA &rs);
  friend std::ostream&
  operator<< (std::ostream &os, const lacksDMA &ls);
};

// derived class with DMA
class hasDMA : public baseDMA
{
private:
  char *style;
public:
  hasDMA (const char *s = "none", const char *l = "null", int r = 0);
  hasDMA (const char *s, const baseDMA &rs);
  hasDMA (const hasDMA &hs); // 拷贝构造函数
  ~hasDMA (); // 析构函数
  hasDMA&
  operator= (const hasDMA &hs); // 赋值运算符
  friend std::ostream&
  operator<< (std::ostream &os, const hasDMA &hs);
};

#endif /* SRC_CLASSES_INHERITS_DMA_H_ */
