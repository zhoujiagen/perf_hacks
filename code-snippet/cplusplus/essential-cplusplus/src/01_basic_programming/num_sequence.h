#ifndef SRC_01_BASIC_PROGRAMMING_NUM_SEQUENCE_H_
#define SRC_01_BASIC_PROGRAMMING_NUM_SEQUENCE_H_

#include <vector>
#include <iostream>
#include <cstdlib> // rand()
#include <time.h> // time()
using namespace std;

enum num_sequence
{
  Fibonacci, Pell, Lucas, Triangular, Square, Pentagonal, COUNT
};

const char * name_seq[] =
  { "Fibonacci", "Pell", "Lucas", "Triangular", "Square", "Pentagonal" };

num_sequence
random_choose_num_sequence ()
{
  srand (time (0));
  return static_cast<num_sequence> ((rand () % COUNT));
}

typedef const vector<unsigned int>* pvec;

typedef const vector<unsigned int>*
(*pfunc) (int);

const int max_elems = 512;

inline bool
check_integrity (int pos)
{
  if (pos <= 0 || pos > max_elems)
    {
      cerr << "!! invalid position: " << pos << " Cannot honor request\n";
      return false;
    }

  return true;
}

pvec
Fibonacci_gen_elems (int pos)
{
  static vector<unsigned int> _elems;

  if (!check_integrity (pos))
    return 0;

  if (_elems.empty ())
    {
      _elems.push_back (1);
      _elems.push_back (1);
    }

  if (_elems.size () < pos)
    {
      int ix = _elems.size ();
      int n_2 = _elems[ix - 2], n_1 = _elems[ix - 1];

      int elem;
      for (; ix < pos; ++ix)
	{
	  elem = n_2 + n_1;
	  _elems.push_back (elem);
	  n_2 = n_1;
	  n_1 = elem;
	}
    }

  return &_elems;
}

pvec
Pell_gen_elems (int pos)
{
  static vector<unsigned int> _elems;

  if (!check_integrity (pos))
    return 0;

  if (_elems.empty ())
    {
      _elems.push_back (1);
      _elems.push_back (2);
    }

  if (_elems.size () < pos)
    {
      int ix = _elems.size ();
      int n_2 = _elems[ix - 2], n_1 = _elems[ix - 1];

      int elem;
      for (; ix < pos; ++ix)
	{
	  elem = n_2 + 2 * n_1;
	  _elems.push_back (elem);
	  n_2 = n_1;
	  n_1 = elem;
	}
    }

  return &_elems;
}

pvec
Lucas_gen_elems (int pos)
{
  static vector<unsigned int> _elems;

  if (!check_integrity (pos))
    return 0;

  if (_elems.empty ())
    {
      _elems.push_back (1);
      _elems.push_back (3);
    }

  if (_elems.size () < pos)
    {
      int ix = _elems.size ();
      int n_2 = _elems[ix - 2], n_1 = _elems[ix - 1];

      int elem;
      for (; ix < pos; ++ix)
	{
	  elem = n_2 + n_1;
	  _elems.push_back (elem);
	  n_2 = n_1;
	  n_1 = elem;
	}
    }

  return &_elems;
}

pvec
Triangular_gen_elems (int pos)
{
  static vector<unsigned int> _elems;

  if (!check_integrity (pos))
    return 0;

  if (_elems.size () < pos)
    {
      int ix = _elems.size () ? _elems.size () + 1 : 1;
      for (; ix <= pos; ++ix)
	_elems.push_back (ix * (ix + 1) / 2);
    }

  return &_elems;
}

pvec
Square_gen_elems (int pos)
{
  static vector<unsigned int> _elems;

  if (!check_integrity (pos))
    return 0;

  if (_elems.size () < pos)
    {
      int ix = _elems.size () ? _elems.size () + 1 : 1;
      for (; ix <= pos; ++ix)
	_elems.push_back (ix * ix);
    }

  return &_elems;
}

pvec
Pentagonal_gen_elems (int pos)
{
  static vector<unsigned int> _elems;

  if (!check_integrity (pos))
    return 0;

  if (_elems.size () < pos)
    {
      int ix = _elems.size () ? _elems.size () + 1 : 1;
      for (; ix <= pos; ++ix)
	_elems.push_back (ix * (3 * ix - 1) / 2);
    }

  return &_elems;
}

pfunc gen_elems[] =
  { Fibonacci_gen_elems, Pell_gen_elems, Lucas_gen_elems, Triangular_gen_elems,
      Square_gen_elems, Pentagonal_gen_elems };

#endif /* SRC_01_BASIC_PROGRAMMING_NUM_SEQUENCE_H_ */
