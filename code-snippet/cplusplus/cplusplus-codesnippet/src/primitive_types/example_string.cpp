#include <iostream>
#include <cstring>

/**
 * 1 C-style string
 * 2 string class
 */
int
main (int argc, char **argv)
{
  using namespace std;

  char cat[]
    { 'f', 'a', 't', 'c', 'a', 't', '\0' };
  cout << cat << endl;

  char bird[11] = "Mr. Cheeps";
  char fish[] = "Bubbles";
  cout << bird << endl;
  cout << fish << endl;
  cout << strlen (bird) << " " << sizeof(bird) << endl;
  cout << strlen (fish) << " " << sizeof(fish) << endl;

  string str = "panther";
  cout << str << ": " << str.size () << endl;

  return 0;
}
