#ifndef SRC_NUMBER_NUMBER_H_
#define SRC_NUMBER_NUMBER_H_

typedef int Number;
Number
randNum ();

float
randFloat ();

#include <complex.h>

typedef float _Complex FloatComplex;
typedef double _Complex DoubleComplex;
typedef long double _Complex LongDoubleComplex;

char*
repr_fc (FloatComplex);

char*
repr_dc (DoubleComplex);

char*
repr_ldc (LongDoubleComplex);

#endif /* SRC_NUMBER_NUMBER_H_ */
