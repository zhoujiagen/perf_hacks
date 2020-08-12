#ifndef SRC_CLASSES_INHERITS_MULTI_WORKER_H_
#define SRC_CLASSES_INHERITS_MULTI_WORKER_H_

#include <string>

using std::string;

class Worker
{
private:
  string fullname;
  long id;
protected:
  virtual void
  Data () const;
public:
  Worker () :
      fullname ("no one"), id (0L)
  {
  }

  Worker (const string &s, long n) :
      fullname (s), id (n)
  {
  }

  virtual
  ~Worker () = 0; // 纯虚函数

  virtual void
  Show () const = 0; // 纯虚函数
};

class Waiter : public virtual Worker // 虚基类
{
private:
  int panache;
protected:
  virtual void
  Data () const;
public:
  Waiter () :
      Worker (), panache (0)
  {
  }

  Waiter (const string &s, long n, int p = 0) :
      Worker (s, n), panache (p)
  {
  }

  Waiter (const Worker &wk, int p = 0) :
      Worker (wk), panache (p)
  {
  }

  void
  Show () const;
};

class Singer : public virtual Worker // 虚基类
{
protected:
  enum
  {
    other, alto, contralto, soprano, bass, baritone, tenor
  };
  static const int Vtypes = 7;
  virtual void
  Data () const;

private:
  static string pv[Vtypes];
  int voice;

public:
  Singer () :
      Worker (), voice (other)
  {
  }

  Singer (const string &s, long n, int v = other) :
      Worker (s, n), voice (v)
  {
  }

  Singer (const Worker &wk, int v = other) :
      Worker (wk), voice (v)
  {
  }

  void
  Show () const;
};

// 多重继承
class SingingWaiter : public Singer, public Waiter
{
protected:
  virtual void
  Data () const;

public:
  SingingWaiter ()
  {
  }

  SingingWaiter (const string &s, long n, int p = 0, int v = other) :
      Worker (s, n), Waiter (s, n, p), Singer (s, n, v)
  {
  }

  SingingWaiter (const Worker &wk, int p = 0, int v = other) :
      Worker (wk), Waiter (wk, p), Singer (wk, v)
  {
  }

  SingingWaiter (const Waiter &wt, int v = other) :
      Worker (wt), Waiter (wt), Singer (wt, v)
  {
  }

  SingingWaiter (const Singer &s, int p = 0) :
      Worker (s), Waiter (s, p), Singer (s)
  {
  }

  void
  Show () const;
};
#endif /* SRC_CLASSES_INHERITS_MULTI_WORKER_H_ */
