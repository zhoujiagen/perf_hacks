#include <iostream>
#include <string>

unsigned int
c_in_str (const char*, char);

void
display (const std::string sa[], int n);

int
main (int argc, char **argv)
{

  using namespace std;

  // C风格字符串

  char ghost[15] = "galloping";
//  char *str = "galloping"; // ISO C++11 does not allow conversion from string literal to 'char *'
  const char *str = static_cast<const char*> ("galloping");
  int n1 = strlen (ghost);
  int n2 = strlen (str);
  int n3 = strlen ("galloping");
  cout << "n1=" << n1 << endl;
  cout << "n2=" << n2 << endl;
  cout << "n3=" << n3 << endl;

  cout << c_in_str (ghost, 'a') << endl;
  cout << c_in_str (str, 'l') << endl;

  // string
  string list[5]
    { "a", "b", "c" };
  display (list, 5);

  return 0;
}

// C风格字符串
unsigned int
c_in_str (const char *str, char ch)
{
  unsigned int result = 0;

  // last is '\0'
  while (*str)
    {
      if (*str == ch)
	result++;
      str++;
    }

  return result;
}

void
display (const std::string sa[], int n)
{
  for (int i = 0; i < n; i++)
    {
      std::cout << i + 1 << ": " << sa[i] << std::endl;
    }
}
