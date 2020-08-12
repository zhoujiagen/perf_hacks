#include <iostream>
#include <cctype>
#include "stack.h"

int
main (int argc, char **argv)
{
  using namespace std;

  Stack st;
  cout << "isempty=" << st.isempty () << endl;
  unsigned long po;

  po = 1;
  st.push (po);
  st.push (2);
  st.push (3);
  cout << "isempty=" << st.isempty () << endl;

  st.pop (po);
  cout << "pop: " << po << endl;
  st.pop (po);
  cout << "pop: " << po << endl;

  return 0;
}
