#include "../include/more_string.h"

int
ALen (char a[])
{
  int i = 0;
  for (; a[i] != 0; i++)
    ;
  return i;
}

int
ACopy (char a[], char b[])
{
  int i = 0;
  for (; (a[i] = b[i]) != 0; i++)
    ;

  return i;
}

int
ACompare (char a[], char b[])
{
  int i = 0;
  for (; a[i] == b[i]; i++)
    {
      if (a[i] == 0)
	return 0;
    }
  return a[i] - b[i];
}

char*
AAppend (char a[], char b[])
{
  return strcpy (a + strlen (a), b);
}

int
PLen (char *a)
{
  char *b = a;
  while (*b++)
    ;
  return b - a - 1;
}

int
PCopy (char *a, char *b)
{
  int i = 0;
  while ((*a++ = *b++) != 0)
    i++;

  return i;
}

int
PCompare (char *a, char *b)
{
  while (*a++ == *b++)
    {
      if (*(a - 1) == 0)
	return 0;
    }

  return *(a - 1) - *(b - 1);
}

char*
PAppend (char *a, char *b)
{
  return strcat (a, b);
}
