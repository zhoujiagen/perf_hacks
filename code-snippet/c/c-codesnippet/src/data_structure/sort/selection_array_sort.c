#include "../include/array_sort.h"

/**
 * 找出数组中最小的元素, 与第一个位置的元素互换;
 * 找出数组中第二小的元素, 与第二个位置的元素互换.
 * 依次类推.
 */

void
sort (Item a[], int l, int r)
{
  int i, j;

  for (i = l; i < r; i++)
    {
      int min = i;
      for (j = i + 1; j <= r; j++)
	{
	  if (less(a[j], a[min]))
	    {
	      min = j;
	    }
	}

      exch(a[i], a[min]);
    }
}
