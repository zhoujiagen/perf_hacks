#ifndef SRC_CLASSES_BINDING_EXAMPLE_BINDING_H_
#define SRC_CLASSES_BINDING_EXAMPLE_BINDING_H_

class Dwelling
{
public:
  virtual
  ~Dwelling ();
  virtual void
  showperks (int a) const;
  virtual Dwelling&
  build (int n);
};

class Hovel : public Dwelling
{
public:
  virtual
  ~Hovel ();
  virtual void
  showpers () const; // 重新定义: 隐藏同名的基类方法
  virtual Hovel&
  build (int n); // 返回类型协变
};

#endif /* SRC_CLASSES_BINDING_EXAMPLE_BINDING_H_ */
