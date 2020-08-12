#ifndef SRC_INCLUDE_BTREE_H_
#define SRC_INCLUDE_BTREE_H_

typedef struct
{
  float value;
  char *name;
} Item;

#include <float.h>
#define NULL_ITEM ((Item){ FLT_MAX, NULL })

typedef struct node *link;
struct node
{
  Item item;
  link l, r;
};

typedef enum
{
  PRE_ORDER, IN_ORDER, POST_ORDER
} Order;

link
new_node (Item item, link l, link r);

void
traverse (Order, link, void
(*visit) (link));

int
count (link);
int
height (link);

#endif /* SRC_INCLUDE_BTREE_H_ */
