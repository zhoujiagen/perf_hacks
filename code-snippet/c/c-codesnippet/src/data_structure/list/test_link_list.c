#include <stdlib.h>
#include <stdio.h>
#include "../include/link_list.h"

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
  int size = (int) (sizeof(item) / sizeof(Item));
  printf ("size=%d\n", size);

  printf ("%d\n", eq_item(item[0], item[0]));
  printf ("%d\n", eq_item(item[0], item[1]));

  // setup
  link head = new_node (item[0]);
  link currentLink = head;
  for (int i = 1; i < size; i++)
    {
      link nextLink = new_node (item[i]);
      currentLink->next = nextLink;
      currentLink = nextLink;
    }

  // visit
  visit_link (head);
  visit_link (head); // visit agin

  link link_again = find_first_by_item_name (head, "again");
  if (link_again != NULL)
    {
      printf ("\n link_again=");
      visit_item (link_again->item);

      delete_next (link_again); // delete

    }
  else
    {
      printf ("\n not found!");
    }

  link link_ok = find_first_by_item_value (head, 3.0f);
  if (link_ok != NULL)
    {
      printf ("\n link_ok=");
      visit_item (link_ok->item);
    }
  else
    {
      printf ("\n not found!");

      if (link_again != NULL)
	{
	  insert_next (link_again, new_node ((Item
		)
		  { 3.0f, "ok" })); // insert
	}
    }

  // reverse
  link r = reverse (head);
  printf ("\n reverse=");
  visit_link (r);
  printf ("\n head=");
  visit_link (head);

  return EXIT_SUCCESS;
}

