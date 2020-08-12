#include <iostream>
#include <cstring>

union one4all
{
  int n_int;
  long n_long;
  double n_double;
};

struct widget
{
  char brand[20];

  int type;
  union id
  {
    long id_num;
    char id_char[20];
  } id_val;
};

void
print (const widget &w)
{
  using namespace std;

  cout << "brand=" << w.brand << ", type=" << w.type << ", id_val=";

  if (w.type == 1)
    {
      cout << w.id_val.id_num << endl;
    }
  else
    {
      cout << w.id_val.id_char << endl;
    }
}

int
main (int argc, char **argv)
{

  using namespace std;

  one4all pail;
  pail.n_int = 15;
  cout << pail.n_int << endl;
  pail.n_double = 1.23;
  cout << pail.n_double << endl;

  widget w
    { "example widget", 1, 10001 };
  print (w);

  strcpy (w.brand, "example widget2");
  w.type = 2;
  strcpy (w.id_val.id_char, "id2");
  print (w);

}
