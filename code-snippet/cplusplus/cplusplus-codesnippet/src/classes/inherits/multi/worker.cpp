#include <iostream>
#include "worker.h"

using std::cout;
using std::endl;

Worker::~Worker ()
{
}

void
Worker::Data () const
{
  cout << "Name: " << fullname << endl;
  cout << "Employee ID: " << id << endl;
}

void
Waiter::Data () const
{
  cout << "Panache rating: " << panache << endl;
}

void
Waiter::Show () const
{
  cout << "Category: waiter" << endl;
  Worker::Data ();
  Data ();
}

string Singer::pv[] =
  { "other", "alto", "contralto", "soprano", "bass", "batitone", "tenor" };

void
Singer::Data () const
{
  cout << "Vocal range: " << pv[voice] << endl;
}

void
Singer::Show () const
{
  cout << "Category: singer" << endl;
  Worker::Data ();
  Data ();
}

void
SingingWaiter::Data () const
{
  Singer::Data ();
  Waiter::Data ();
}

void
SingingWaiter::Show () const
{
  cout << "Category: singing waiter" << endl;
  Worker::Data ();
  Data ();
}

