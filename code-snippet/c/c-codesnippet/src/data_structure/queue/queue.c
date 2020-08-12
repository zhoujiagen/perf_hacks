#include <stdlib.h>
#include <assert.h>
#include "../include/queue.h"

static link head, tail;
static int current_size = 0;

void
queue_init (int capcity)
{
  head = NULL;
  tail = NULL;
}

int
queue_empty ()
{
  return (current_size == 0);
}

int
queue_size ()
{
  return current_size;
}

/**
 * put to tail
 */
void
queue_put (Item item)
{
  link l = new_node (item);
  if (tail == NULL)
    {
      tail = l;
      if (head == NULL)
	{
	  head = l;
	}
    }
  else
    {
      link t = tail;
      t->next = l;
      tail = l;
    }

  current_size++;
}

/**
 * get from head
 */
Item
queue_get ()
{
  assert(current_size > 0);

  link t = head;
  Item item = t->item;

  if (tail == head)
    {
      tail = t->next;
    }
  head = t->next;
  free_node (t);
  current_size--;

  return item;

}
