// numeric_gcd.cxx

#include <iostream>
#include "include/numeric.hxx"


int main()
{
  int m = 8;
  int n = 12;

  auto result = cmb::gcd(m, n);

  std::cout << "gcd(m, n) = " << result << std::endl; // = 4
}