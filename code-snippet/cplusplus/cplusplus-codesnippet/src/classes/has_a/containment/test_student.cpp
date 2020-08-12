#include<iostream>
#include "student.h"

const int pupils = 3;
const int quizzes = 5;

int
main (int argc, char **argv)
{

  const double scores1[] =
    { 92, 94, 96, 93, 95 };
  Student s1 ("Gil Bayts", scores1, 5);
  const double scores2[] =
    { 83, 89, 72, 78, 95 };
  Student s2 ("Pat Roone", scores2, 5);
  const double scores3[] =
    { 92, 89, 96, 74, 64 };
  Student s3 ("Fleur O'Day", scores3, 5);

  Student ada[pupils] =
    { s1, s2, s3 };

  int i;
  for (i = 0; i < pupils; i++)
    {
      std::cout << ada[i] << std::endl;
    }

  return 0;
}
