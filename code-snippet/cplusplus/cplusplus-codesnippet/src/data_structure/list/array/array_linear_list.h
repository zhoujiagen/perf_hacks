#ifndef SRC_DATA_STRUCTURE_LIST_ARRAY_ARRAY_LINEAR_LIST_H_
#define SRC_DATA_STRUCTURE_LIST_ARRAY_ARRAY_LINEAR_LIST_H_

#include "../../include/core.h"
#include "linear_list.h"

#include <iostream>
#include <sstream>

using std::ostream;
using std::string;

template<class T>
  class arrayLinearList : public linearList<T>
  {
  public:
    arrayLinearList (int initialCapacity = 10);
    arrayLinearList (const arrayLinearList<T>&);
    ~arrayLinearList ()
    {
      delete[] element;
    }

    bool
    empty () const
    {
      return listSize == 0;
    }

    int
    size () const
    {
      return listSize;
    }

    T&
    get (int theIndex) const;

    int
    indexOf (const T &theElement) const;

    void
    erase (int theIndex);

    void
    insert (int theIndex, const T &theElement);

    void
    output (ostream &out) const;

    /**
     * @return 容量
     */
    int
    capacity () const
    {
      return arrayLength;
    }

  protected:

    void
    checkIndex (int theIndex) const; /**< 若索引无效, 则抛出异常. */
    T *element; /**< 存储线性表元素的一维数组 */
    int arrayLength; /**< 一维数组的容量 */
    int listSize; /**< 线性表的元素个数 */

  };

template<class T>
  arrayLinearList<T>::arrayLinearList (int initialCapacity)
  {
    if (initialCapacity < 1)
      {
	std::ostringstream s;
	s << "Initial capacity = " << initialCapacity << " Must be > 0";
	throw illegalParameterValue (s.str ());
      }

    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
  }

template<class T>
  arrayLinearList<T>::arrayLinearList (const arrayLinearList<T> &theList)
  {
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    std::copy (theList.element, theList.element + listSize, element);
  }

template<class T>
  void
  arrayLinearList<T>::checkIndex (int theIndex) const
  {
    if (theIndex < 0 || theIndex >= listSize)
      {
	std::ostringstream s;
	s << "checkIndex: index = " << theIndex << " size = " << listSize;
	throw illegalParameterValue (s.str ());
      }
  }

template<class T>
  T&
  arrayLinearList<T>::get (int theIndex) const
  {
    checkIndex (theIndex);
    return element[theIndex];
  }

template<class T>
  int
  arrayLinearList<T>::indexOf (const T &theElement) const
  {
    int theIndex = (int) (std::find (element, element + listSize, theElement)
	- element);

    if (theIndex == listSize)
      return -1;
    else
      return theIndex;
  }

template<class T>
  void
  arrayLinearList<T>::erase (int theIndex)
  {
    checkIndex (theIndex);

    std::copy (element + theIndex + 1, element + listSize, element + theIndex);

    element[--listSize].~T (); // 最后一个元素调用析构函数
  }

template<class T>
  void
  arrayLinearList<T>::insert (int theIndex, const T &theElement)
  {
    if (theIndex < 0 || theIndex > listSize)
      {
	std::ostringstream s;
	s << "insert: index = " << theIndex << " size = " << listSize;
	throw illegalParameterValue (s.str ());
      }

    if (listSize == arrayLength)
      {
	changeLength1D (element, arrayLength, 2 * arrayLength);
	arrayLength *= 2;
      }

    std::copy_backward (element + theIndex, element + listSize,
			element + listSize + 1);
    element[theIndex] = theElement;
    listSize++;
  }

template<class T>
  void
  arrayLinearList<T>::output (ostream &out) const
  {
    std::copy (element, element + listSize,
	       std::ostream_iterator<T> (std::cout, " "));
  }

template<class T>
  ostream&
  operator<< (ostream &out, const arrayLinearList<T> &x)
  {
    x.output (out);
    return out;
  }

#endif /* SRC_DATA_STRUCTURE_LIST_ARRAY_ARRAY_LINEAR_LIST_H_ */
