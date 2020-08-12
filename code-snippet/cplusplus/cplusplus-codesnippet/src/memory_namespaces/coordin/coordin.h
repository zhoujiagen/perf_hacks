#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
  double distance;
  double angle;
};

struct rect
{
  double x;
  double y;
};

// 原型
polar
rect_to_polar (rect r);

void
show_polar (polar p);

#endif /* COORDIN_H_ */
