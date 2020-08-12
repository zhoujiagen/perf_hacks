#ifndef SRC_TEMPLATES_CLASS_TEMPLATE_STACK_TP_H_
#define SRC_TEMPLATES_CLASS_TEMPLATE_STACK_TP_H_

//! 说明: 将所有模板信息放在一个头文件中.

/** 栈模板类 */
template<class T>
  class Stack
  {
  private:
    static const int MAX = 10;
    T items[MAX];
    int top;

  public:
    Stack ();
    bool
    isempty ();
    bool
    isfull ();
    bool
    push (const T &item);
    bool
    pop (T &item);

  };

template<class T>
  Stack<T>::Stack ()
  {
    top = 0;
  }

template<class T>
  bool
  Stack<T>::isempty ()
  {
    return top == 0;
  }

template<class T>
  bool
  Stack<T>::isfull ()
  {
    return top == MAX;
  }

template<class T>
  bool
  Stack<T>::push (const T &item)
  {
    if (top < MAX)
      {
	items[top++] = item;
	return true;
      }
    else
      return false;
  }

template<class T>
  bool
  Stack<T>::pop (T &item)
  {
    if (top > 0)
      {
	item = items[--top];
	return true;
      }
    else
      return false;
  }

#endif /* SRC_TEMPLATES_CLASS_TEMPLATE_STACK_TP_H_ */
