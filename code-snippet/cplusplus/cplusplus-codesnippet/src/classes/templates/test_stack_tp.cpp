#include <iostream>
#include <string>
#include "stack_tp.h"

int
main (int argc, char **argv)
{

  using namespace std;

  using std::string;

  Stack<string> st;
  st.push ("1");
  st.push ("2");
  string value;
  st.pop (value);
  cout << "value = " << value << endl;

  return 0;
}
