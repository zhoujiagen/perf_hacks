#ifndef SRC_INCLUDE_ARRAY_SORT_H_
#define SRC_INCLUDE_ARRAY_SORT_H_

typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define compexch(A,B) if(less(B,A)) exch(A,B)

void
sort (Item a[], int l, int r);

#endif /* SRC_INCLUDE_ARRAY_SORT_H_ */
