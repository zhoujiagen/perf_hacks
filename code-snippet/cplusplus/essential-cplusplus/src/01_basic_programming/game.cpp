#include "num_sequence.h"

int
main (int argc, char **argv)
{
  bool go_for_it = true; // user want to guess?
  bool got_it = false; // user guessed correctly?

  // for debug
  for (int i = 0; i < COUNT; i++)
    {
      pfunc pf = gen_elems[i];
      pvec pv = pf (max_elems);
      cout << name_seq[i] << ": ";
      for (int j = 0; j < pv->size (); j++)
	{
	  cout << (*pv)[j] << " ";
	}
      cout << endl;
    }
  cout << endl;

  num_sequence ns = random_choose_num_sequence ();
  pfunc pf = gen_elems[ns];
  pvec pv = pf (max_elems);
  cout << name_seq[ns] << ": The first two elements of the series are: "
      << (*pv)[0] << ", " << (*pv)[1] << endl;

  int pos = 2;

  while ((got_it == false) && (go_for_it == true))
    {

      if (pos >= max_elems)
	{
	  cout << "excellent!" << endl;
	  break;
	}
      cout << "What is the next element? ";

      unsigned int user_guess;
      cin >> user_guess;
      got_it = (*pv)[pos] == user_guess;
      if (got_it)
	{
	  cout << "yes!" << endl;
	  got_it = false;
	  pos++;
	}
      else
	{
	  cout << "no! Would you like to try again? (y/n) ";
	  char user_resp;
	  cin >> user_resp;
	  if (user_resp == 'N' || user_resp == 'n')
	    {
	      go_for_it = false;
	    }
	}

    }

}
