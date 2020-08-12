#ifndef SRC_INCLUDE_POINT_H_
#define SRC_INCLUDE_POINT_H_

typedef struct
{
  float x;
  float y;
} point;

float
distance (point, point);

/**
 * shortest path between point
 */
point
shortest (point *a, int n);

#endif /* SRC_INCLUDE_POINT_H_ */
