#include <iostream>
#include <cstring>

struct inflatable
{
  char name[20];
  float volume;
  double price;
};

void
print (const inflatable &i)
{
  using namespace std;

  cout << "name=" << i.name << ", volume=" << i.volume << ", price=" << i.price
      << endl;
}

int
main (int argc, char **argv)
{

  using namespace std;

  inflatable guest =
    { "Glorious Gloria", 1.88, 29.99, };
  print (guest);

  inflatable guests[2]
    {
      { "Bambi", 0.5, 21.99, },
      { "Godzilla", 2000, 565.99, }, };
  print (guests[0]);

  // memory management: new, delete

  inflatable *p_inflatable = new inflatable;
  strcpy (p_inflatable->name, "Fabulous Frodo");
  p_inflatable->volume = 1.4;
  p_inflatable->price = 27.99;
  print (*p_inflatable);
  delete p_inflatable;

  return 0;
}

