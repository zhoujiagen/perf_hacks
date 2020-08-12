#include <iostream>
#include "array_linear_list.h"
#include "../../include/core.h"

int
main (int argc, char **argv)
{
  using namespace std;

  arrayLinearList<int> *x = new arrayLinearList<int> (100);

  try
    {
      x->insert (0, 1);
      x->insert (1, 2);
      x->output (cout);
    }
  catch (illegalParameterValue e)
    {
      e.outputMessage ();
    }

  return 0;
}
