#include <iostream>

#include "./QuartzParchmentShears/QuartzParchmentShearsGameplay.h"

int main()
{
  std::cout.setf(std::ios::fixed);
  std::cout.setf(std::ios::showpoint);
  std::cout.precision(2);
  srand(time(NULL));

  QuartzParchmentShearsGameplay();

  return 0;
}
