#include <iostream>
#include "my_queue.h"

MyQueue::MyQueue (int qs) :
    qsize (qs)
{
  front = rear = nullptr;
  items = 0;
}

MyQueue::~MyQueue ()
{
  Node *temp;
  while (front != nullptr)
    {
      temp = front;
      front = front->next;
      delete temp;
    }
}

bool
MyQueue::isempty () const
{
  return items == 0;
}

bool
MyQueue::isfull () const
{
  return items == qsize;
}

int
MyQueue::queuecount () const
{
  return items;
}

bool
MyQueue::enqueue (const Item &item)
{
  if (isfull ())
    return false;

  Node *add = new Node;
  add->item = item;
  add->next = nullptr;
  items++;

  if (front == nullptr)
    front = add;
  else
    rear->next = add;
  rear = add;
  return true;
}

bool
MyQueue::dequeue (Item &item)
{
  if (front == nullptr)
    return false;

  item = front->item;
  items--;

  Node *temp = front;
  front = front->next;
  delete temp;

  if (items == 0)
    rear = nullptr;

  return true;
}
