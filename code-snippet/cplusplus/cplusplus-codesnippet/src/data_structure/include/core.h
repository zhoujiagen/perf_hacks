#ifndef SRC_DATA_STRUCTURE_INCLUDE_CORE_H_
#define SRC_DATA_STRUCTURE_INCLUDE_CORE_H_

#include <iostream>
#include <string>

using std::string;

/**
 * 非法参数值异常类.
 */
class illegalParameterValue
{
public:
  illegalParameterValue () :
      message ("Illegal parameter value")
  {
  }

  illegalParameterValue (string theMessage)
  {
    message = theMessage;
  }

  void
  outputMessage ()
  {
    std::cout << message << std::endl;
  }

private:
  string message;
};

template<class T>
  void
  changeLength1D (T *&a, int oldLength, int newLength)
  {

    if (newLength < 0)
      throw illegalParameterValue ("new length must be >= 0");

    T *temp = new T[newLength];
    int number = std::min (oldLength, newLength);
    std::copy (a, a + number, temp);
    delete[] a;
    a = temp;
  }

#endif /* SRC_DATA_STRUCTURE_INCLUDE_CORE_H_ */
