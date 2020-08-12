#include <memory_namespaces/coordin/coordin.h>
#include <iostream>
#include <cmath>

polar
rect_to_polar (rect r)
{
  polar result;

  result.distance = std::sqrt (r.x * r.x + r.y * r.y);
  result.angle = std::atan2 (r.y, r.x);

  return result;
}

void
show_polar (polar p)
{
  const double Rad_to_deg = 57.29577951;

  std::cout << "distance=" << p.distance << ", angle=" << p.angle * Rad_to_deg
      << " degrees." << std::endl;
}
