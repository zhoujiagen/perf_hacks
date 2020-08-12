#include <memory_namespaces/coordin/coordin.h>

int
main (int argc, char **argv)
{
  rect r =
    { 3, 4 };
  polar p = rect_to_polar (r);
  show_polar (p);

  return 0;
}
