#include <iostream>
#include <cmath>

struct travel_time
{
  int hours;
  int minutes;
};

const int MINUTES_PER_HOUR = 60;

travel_time
sum (travel_time t1, travel_time t2);
void
show_time (travel_time t);

/** 直角坐标. */
struct rect
{
  double x;
  double y;
};

/** 极坐标. */
struct polar
{
  double distance;
  double angle;
};

polar
rect_to_polar (rect r);
/**
 * r: in
 * p: out
 */
void
rect_to_polar (const rect *r, polar *p);
void
show_polar (const polar *p); // 传递结构地址

int
main (int argc, char **argv)
{
  using namespace std;

  // case 1
  travel_time t1 =
    { 5, 45 };
  travel_time t2 =
    { 4, 55 };

  travel_time trip = sum (t1, t2);
  show_time (trip);

  travel_time t3 =
    { 4, 32 };
  show_time (sum (trip, t3));

  // case 2
  rect r =
    { 3, 4 };
  polar p = rect_to_polar (r);
  show_polar (&p);

  polar p2;
  rect_to_polar (&r, &p2);
  show_polar (&p2);

  return 0;
}

travel_time
sum (travel_time t1, travel_time t2)
{
  travel_time result;
  result.minutes = (t1.minutes + t2.minutes) % MINUTES_PER_HOUR;
  result.hours = t1.hours + t2.hours
      + (t1.minutes + t2.minutes) / MINUTES_PER_HOUR;
  return result;
}
void
show_time (travel_time t)
{
  using namespace std;

  cout << t.hours << " hours, " << t.minutes << " minutes." << endl;
}

polar
rect_to_polar (rect r)
{
  polar result;

  result.distance = std::sqrt (r.x * r.x + r.y * r.y);
  result.angle = std::atan2 (r.y, r.x);

  return result;
}

void
rect_to_polar (const rect *r, polar *p)
{
  p->distance = std::sqrt (r->x * r->x + r->y * r->y);
  p->angle = std::atan2 (r->y, r->x);
}

void
show_polar (const polar *p)
{
  const double Rad_to_deg = 57.29577951;

  std::cout << "distance=" << p->distance << ", angle=" << p->angle * Rad_to_deg
      << " degrees." << std::endl;
}
