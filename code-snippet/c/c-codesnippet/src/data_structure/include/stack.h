#ifndef SRC_INCLUDE_STACK_H_
#define SRC_INCLUDE_STACK_H_

#include "item.h"

void
stack_init (int);

int
stack_empty ();

int
stack_size ();

void
stack_push (Item);

Item
stack_pop ();

#endif /* SRC_INCLUDE_STACK_H_ */
