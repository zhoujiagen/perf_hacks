#ifndef SRC_DATA_STRUCTURE_LIST_ARRAY_LINEAR_LIST_H_
#define SRC_DATA_STRUCTURE_LIST_ARRAY_LINEAR_LIST_H_

#include <iostream>

using std::ostream;

/** 线性表抽象类. */
template<class T>
  class linearList
  {
  public:
    virtual
    ~linearList ()
    {
    }

    /** @return true, 当且仅当线性表为空 */
    virtual bool
    empty () const = 0;

    /** @return 线性表的元素个数 */
    virtual int
    size () const = 0;

    /** @return 索引为theIndex的元素 */
    virtual T&
    get (int theIndex) const = 0;

    /** @return 元素theElement第一次出现时的索引 */
    virtual int
    indexOf (const T &theElement) const = 0;

    /** 删除索引为theIndex的元素.
     * @param theIndex 元素索引
     */
    virtual void
    erase (int theIndex) = 0;

    /** 将theElement插入线性表中索引为theIndex的位置上.
     * @param theIndex 插入位置索引
     * @aram theElement 元素
     */
    virtual void
    insert (int theIndex, const T &theElement) = 0;

    /** 线性表输出.
     * @param out 输出流
     */
    virtual void
    output (ostream &out) const = 0;
  };

#endif /* SRC_DATA_STRUCTURE_LIST_ARRAY_LINEAR_LIST_H_ */
