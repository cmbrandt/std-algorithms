// numeric_lcm.cxx

#include <iostream>
#include "include/numeric.hxx"


int main()
{
  int m = 8;
  int n = 12;

  auto result = cmb::lcm(m, n);

  std::cout << "cmb::lcm(m, n) = " << result << std::endl; // = 24
}