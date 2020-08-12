#ifndef SRC_INCLUDE_ITEM_H_
#define SRC_INCLUDE_ITEM_H_

typedef struct
{
  float value;
  char *name;
} Item;

// (1) macro
#include <float.h>
#define NULL_ITEM ((Item){ FLT_MAX, NULL })
// (2) external linkage: note definitions in link_list.c
//extern const Item NULL_ITEM; // declaration

#include <string.h>
#define eq_item(A, B) (A.value == B.value && strcmp(A.name, B.name) == 0)

typedef struct node *link;
struct node
{
  Item item;
  link next;
};

link
new_node (Item item);
void
free_node (link);

link
get_next (link);
Item
get_item (link);

char*
repr (Item);
void
visit_item (Item);
void
visit_link (link);
link
reverse (link);

#endif /* SRC_INCLUDE_ITEM_H_ */
