#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <assert.h>
#include <string.h>
#include "../include/link_list.h"

// see declaration in link_list.h
//const Item NULL_ITEM = (Item
//      )
//	{ FLT_MAX, NULL };



void
insert_next (link l, link t)
{
  assert(l != NULL && t != NULL);

  t->next = l->next;
  l->next = t;
}

link
delete_next (link l)
{
  assert(l != NULL);

  link t = l->next;
  l->next = t->next;
  return t;
}

link
find_first_by_item_value (link l, float item_value)
{
  assert(l != NULL);

  link t = l;
  while (t != NULL)
    {
      if (t->item.value == item_value)
	{
	  return t;
	}

      t = t->next;
    }
  return NULL;
}
link
find_first_by_item_name (link l, char *item_name)
{
  assert(l != NULL && item_name != NULL);

  link t = l;
  while (t != NULL)
    {
      if (strcmp (t->item.name, item_name) == 0)
	{
	  return t;
	}

      t = t->next;
    }
  return NULL;
}
