#include <stdio.h>
#include <stdlib.h>
#include "../include/point.h"
#include "../include/number.h"

int
main (int argc, char **argv)
{
  point x =
    { 1.0, 2.0 };
  point y =
    { 2.0, 3.0 };
  float d = distance (x, y);
  printf ("%f\n", d);

  int n = 5, i;
  point *a = malloc (sizeof(point) * n);
  for (i = 0; i < n; i++)
    {
      a[i].x = randFloat ();
      a[i].y = randFloat ();
      printf ("point: %f, %f\n", a[i].x, a[i].y);
    }
  point s = shortest (a, n);
  printf ("shortest: %f, %f\n", s.x, s.y);

}

