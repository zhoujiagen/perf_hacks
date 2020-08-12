#ifndef SRC_INCLUDE_QUEUE_H_
#define SRC_INCLUDE_QUEUE_H_

#include "item.h"

void
queue_init (int);

int
queue_empty ();

int
queue_size ();

void
queue_put (Item);

Item
queue_get ();

#endif /* SRC_INCLUDE_QUEUE_H_ */
