#include <iostream>
#include "table_tennis.h"

int
main (int argc, char **argv)
{
  using namespace std;

  TableTennisPlayer player1 ("Chunk", "Blizzard", true);
  TableTennisPlayer player2 ("Tara", "Boomdea", false);
  player1.Name ();
  player2.Name ();
  cout << endl;

  RatedPlayer rplayer1 (1140, "Mallory", "Duck", true);
  rplayer1.Name ();
  RatedPlayer rplayer2 (1212, player2);
  rplayer2.Name ();
  cout << endl;

  TableTennisPlayer &rt = rplayer1;
  TableTennisPlayer *pt = &rplayer1;
  rt.Name ();
  pt->Name ();

  return 0;
}

