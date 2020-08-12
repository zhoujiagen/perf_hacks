#include <stdio.h>
#include <stdlib.h>
#include "../include/number.h"

double
Real (DoubleComplex dc)
{
  return creal (dc);
}
double
Imag (DoubleComplex dc)
{
  return cimag (dc);
}

int
main (int argc, char **argv)
{
  Number a = randNum ();
  printf ("%d\n", a);


  // https://stackoverflow.com/questions/6418807/how-to-work-with-complex-numbers-in-c
  FloatComplex fc = 1.0 + 3.0 * I;
  char *s = repr_fc (fc);
  printf ("fc=%s.\n", s);
  free (s);

  DoubleComplex dc = 1.0 + 3.0 * I;
  s = repr_dc (dc);
  printf ("dc=%s.\n", s);
  free (s);

  LongDoubleComplex ldc = 1.0 + 3.0 * I;
  s = repr_ldc (ldc);
  printf ("ldc=%s.\n", s);
  free (s);

  DoubleComplex dc1 = 1.0 + 3.0 * I;
  DoubleComplex dc2 = 1.0 - 4.0 * I;
  s = repr_dc (dc1);
  printf ("dc1=%s.\n", s);
  free (s);
  s = repr_dc (dc2);
  printf ("dc2=%s.\n", s);
  free (s);

  DoubleComplex sum = dc1 + dc2;
  s = repr_dc (sum);
  printf ("sum=%s.\n", s);
  free (s);

  DoubleComplex difference = dc1 - dc2;
  s = repr_dc (difference);
  printf ("difference=%s.\n", s);
  free (s);

  DoubleComplex product = dc1 * dc2;
  s = repr_dc (product);
  printf ("product=%s.\n", s);
  free (s);

  DoubleComplex quotient = dc1 / dc2;
  s = repr_dc (quotient);
  printf ("quotient=%s.\n", s);
  free (s);

  DoubleComplex conjugate = conj (dc1);
  s = repr_dc (conjugate);
  printf ("conjugate=%s.\n", s);
  free (s);

}

