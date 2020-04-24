// numeric_lcm.cxx

#include <iostream>
#include "include/numeric.hxx"


int main()
{
  int m = 8;
  int n = 12;

  auto r = cmb::lcm(m, n);

  std::cout << "result = " << r << std::endl; // = 24
}