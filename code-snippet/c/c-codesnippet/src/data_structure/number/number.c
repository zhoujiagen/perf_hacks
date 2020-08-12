#include <stdio.h>
#include <stdlib.h>
#include "../include/number.h"

Number
randNum ()
{
  return rand ();
}

float
randFloat ()
{
  return 1.0 * rand () / RAND_MAX;
}

// https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c

char*
repr_fc (FloatComplex c)
{
  // tell the length
  int length = snprintf(NULL, 0, "(%f, %f)", creal (c), cimag (c));
  char *s = (char*) malloc (length);
  snprintf(s, length + 1, "(%f, %f)", creal (c), cimag (c));
  return s;
}

char*
repr_dc (DoubleComplex c)
{
  int length = snprintf(NULL, 0, "(%f, %f)", creal (c), cimag (c));
  char *s = (char*) malloc (length);
  snprintf(s, length + 1, "(%f, %f)", creal (c), cimag (c));
  return s;
}

char*
repr_ldc (LongDoubleComplex c)
{
  int length = snprintf(NULL, 0, "(%f, %f)", creal (c), cimag (c));
  char *s = (char*) malloc (length);
  snprintf(s, length + 1, "(%f, %f)", creal (c), cimag (c));
  return s;
}
