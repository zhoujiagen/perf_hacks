#include <stdio.h>
#include "../include/stack.h"

int
main (int argc, char **argv)
{
  stack_init (-1);

  Item item[] =
    {
      { 0.0f, "hello" },
      { 1.0f, "there" },
      { 2.0f, "again" }, //
	  { 3.0f, "ok" },
	  { 4.0, "bye" } };
  int size = (int) (sizeof(item) / sizeof(Item));
  for (int i = 0; i < size; i++)
    {
      stack_push (item[i]);
    }
  for (int i = 0; i < size; i++)
    {
      Item t = stack_pop ();
      visit_item (t);
    }

  Item t = stack_pop ();
  visit_item (t);
}
