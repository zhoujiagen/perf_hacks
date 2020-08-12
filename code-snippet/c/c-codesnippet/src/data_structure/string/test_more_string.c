#include <stdio.h>
#include <string.h>
#include "../include/more_string.h"

int
main (int argc, char **argv)
{
  // array
  char a[] = "hello, there";
  char b[] = "hello, again!!!";
  printf ("a=%s\n", a);
  printf ("b=%s\n", b);

  printf ("len(a)=%d\n", ALen (a));
  printf ("acopy=%d\n", ACopy (a, b));
  printf ("a=%s\n", a);

// pointer
  // char *pa = "hello, there"; // 字符串字面量: 不能修改
  char aa[] = "hello, there";
  char bb[] = "hello, again!!!";
  char *pa = aa;
  char *pb = bb;
  printf ("pa=%s\n", pa);
  printf ("pb=%s\n", pb);

  printf ("len(pa)=%d\n", PLen (pa));
  printf ("pcopy=%d\n", PCopy (pa, pb));
  printf ("pa=%s\n", pa);

}
