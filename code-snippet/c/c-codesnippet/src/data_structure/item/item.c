#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/item.h"

link
new_node (Item item)
{
  link l = (struct node*) malloc (sizeof(struct node));
  if (l == NULL)
    {
      printf ("WARN: allocate node failed!\n");
    }
  l->item = item;
  l->next = NULL; // malloc不会执行初始化
  return l;
}

void
free_node (link l)
{
  assert(l != NULL);

  free (l);
}

link
get_next (link l)
{
  assert(l != NULL);

  return l->next;
}
Item
get_item (link l)
{
  assert(l != NULL);

  return l->item;
}

char*
repr (Item item)
{
  char *s = (char*) malloc (sizeof(Item) + 2);
  sprintf (s, "%f,%s", item.value, item.name);
  return s;
}

void
visit_item (Item item)
{
  printf ("%f,%s ", item.value, item.name);
}

void
visit_link (link l)
{
  assert(l != NULL);

//	visit_item(l->item);
//	if (l->next != NULL) {
//		traverse(l->next);
//	}

  link t = l;
  for (; t != NULL ; t = t->next)
    {
      visit_item (t->item);
    }
  printf ("\n");
}

link
reverse (link l)
{
  link r = NULL; // already processed
  link y = l; // not processed

  while (y != NULL )
    {
      link t = y->next;
      y->next = r;
      r = y; // progressing
      y = t;
    }

  return r;
}
