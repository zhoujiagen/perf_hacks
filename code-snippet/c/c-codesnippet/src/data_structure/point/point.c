#include <math.h>
#include <float.h>
#include "../include/point.h"

float
distance (point x, point y)
{
  float dx = x.x - y.x;
  float dy = x.y - y.y;
  return sqrt (dx * dx + dy * dy);
}

point
shortest (point *a, int n)
{
  point result =
    { 0, 0 };
  int i, j;
  float d = FLT_MAX, temp;
  for (i = 0; i < n; i++)
    {
      for (j = i + 1; j < n; j++)
	{
	  temp = distance (a[i], a[j]);
	  if (temp < d)
	    {
	      d = temp;
	      result.x = i;
	      result.y = j;
	    }
	}
    }

  return result;
}
