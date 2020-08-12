#include <iostream>
#include "stone_wt.h"

StoneWT::StoneWT (double lbs)
{
  std::cout << "StoneWT (double lbs)" << std::endl;
  pounds = lbs;

  stone = int (lbs) / LBS_PER_STN;
  pds_left = lbs - int (lbs) + int (lbs) % LBS_PER_STN;
}

StoneWT::StoneWT (int stn, double lbs)
{
  std::cout << "StoneWT (int stn, double lbs)" << std::endl;
  stone = stn;
  pds_left = lbs;
  pounds = stn * LBS_PER_STN + lbs;
}

StoneWT::StoneWT ()
{
  std::cout << "StoneWT ()" << std::endl;
  stone = pds_left = pounds = 0;
}

StoneWT::~StoneWT ()
{
  std::cout << "~StoneWT ()" << std::endl;
}

void
StoneWT::show_lbs () const
{
  std::cout << pounds << " pounds" << std::endl;
}

void
StoneWT::show_stn () const
{
  std::cout << stone << " stone, " << pds_left << " pounds" << std::endl;
}

StoneWT::operator int () const
{
  std::cout << "operator int ()" << std::endl;
  return int (pounds + 0.5);
}

StoneWT::operator double () const
{
  std::cout << "operator double ()" << std::endl;
  return pounds;
}
