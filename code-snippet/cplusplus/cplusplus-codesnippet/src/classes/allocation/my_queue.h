#ifndef SRC_CLASSES_ALLOCATION_MY_QUEUE_H_
#define SRC_CLASSES_ALLOCATION_MY_QUEUE_H_

typedef unsigned long Item;

class MyQueue
{
private:
  static const int Q_SIZE = 10;
  struct Node
  {
    Item item;
    struct Node *next;
  };
  Node *front;
  Node *rear;
  int items;	  // 队列中当前元素数量
  const int qsize; // 队列最大容量

public:
  MyQueue (int qs = Q_SIZE);
  ~MyQueue ();
  bool
  isempty () const;
  bool
  isfull () const;
  int
  queuecount () const;
  bool
  enqueue (const Item &item);
  bool
  dequeue (Item &item);
};

#endif /* SRC_CLASSES_ALLOCATION_MY_QUEUE_H_ */
