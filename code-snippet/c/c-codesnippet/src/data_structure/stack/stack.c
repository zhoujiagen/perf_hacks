#include <stdlib.h>
#include <assert.h>
#include "../include/stack.h"

// statck size
static int current_stack_size = 0;

// stack top
static link stack_top = NULL;

void
stack_init (int capacity)
{
  // do nothing
}

int
stack_empty ()
{
  return (current_stack_size == 0);
}

int
stack_size ()
{
  return current_stack_size;
}

void
stack_push (Item item)
{
  link t = (struct node*) malloc (sizeof(struct node));
  t->item = item;
  t->next = NULL;

  if (stack_top == NULL)
    {
      stack_top = t;
    }
  else
    {
      t->next = stack_top;
      stack_top = t;
    }

  current_stack_size++;
}

Item
stack_pop ()
{
  assert(current_stack_size > 0);

  link t = stack_top;
  Item item = t->item;
  stack_top = t->next;

  free_node (t);
  current_stack_size--;

  return item;
}
