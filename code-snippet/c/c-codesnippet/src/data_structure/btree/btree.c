#include "../include/btree.h"
#include <stdlib.h>

link
new_node (Item item, link l, link r)
{
  link result = malloc (sizeof(struct node));
  result->item = item;
  result->l = l;
  result->r = r;
  return result;
}

void
traverse (Order order, link l, void
(*visit) (link))
{
  if (l == NULL)
    return;

  if (order == PRE_ORDER)
    {
      (*visit) (l);
      traverse (order, l->l, visit);
      traverse (order, l->r, visit);
    }
  else if (order == IN_ORDER)
    {
      traverse (order, l->l, visit);
      (*visit) (l);
      traverse (order, l->r, visit);
    }
  else
    {
      traverse (order, l->l, visit);
      traverse (order, l->r, visit);
      (*visit) (l);
    }

}

int
count (link l)
{
  if (l == NULL)
    return 0;
  return count (l->l) + count (l->r);
}

int
height (link l)
{
  int lh, rh;
  if (l == NULL)
    return -1;
  lh = height (l->l);
  rh = height (l->r);
  if (lh > rh)
    {
      return lh + 1;
    }
  else
    {
      return rh + 1;
    }
}
