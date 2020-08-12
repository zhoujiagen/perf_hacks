#include "../include/btree.h"
#include <stdio.h>

void
visit_item (link l)
{
  if (l == NULL)
    return;
  printf ("%f,%s ", l->item.value, l->item.name);
}

int
main (int argc, char **argv)
{
  Item item[] =
    {
      { 0.0f, "hello" },
      { 1.0f, "there" },
      { 2.0f, "again" }, //
	  { 3.0f, "ok" },
	  { 4.0, "bye" } };

  link there = new_node (item[1], NULL, NULL);

  link ok = new_node (item[3], NULL, NULL);
  link bye = new_node (item[4], NULL, NULL);
  link again = new_node (item[2], ok, bye);

  link hello = new_node (item[0], there, again);

  traverse(IN_ORDER, hello, visit_item);
}

