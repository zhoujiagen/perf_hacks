#include "../include/array_sort.h"

#include <stdlib.h>
#include <stdio.h>

static int N = 10;

void
print (int a[])
{
  for (int i = 0; i < N; i++)
    {
      printf ("%3d ", a[i]);
    }
  printf ("\n");
}

int
main (int argc, char **argv)
{
  int *a = malloc (N * sizeof(int));
  int i;
  for (i = 0; i < N; i++)
    {
      a[i] = 1000 * (1.0 * rand () / RAND_MAX);
    }

  print (a);

  sort (a, 0, N - 1);
  print (a);

}
