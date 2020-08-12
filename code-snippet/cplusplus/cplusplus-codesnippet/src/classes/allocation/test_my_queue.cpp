#include <iostream>
#include "my_queue.h"

int
main (int argc, char **argv)
{
  using namespace std;

  MyQueue q (3);
  q.enqueue (1);
  q.enqueue (2);
  q.enqueue (3);
  q.enqueue (4);

  Item item;
  cout << q.dequeue (item) << ", " << item << endl;
  cout << q.dequeue (item) << ", " << item << endl;
  cout << q.dequeue (item) << ", " << item << endl;
  cout << q.dequeue (item) << ", " << item << endl;

  return 0;
}
