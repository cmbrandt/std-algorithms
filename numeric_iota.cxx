// numeric_iota.cxx

#include <iostream>
#include <vector>
#include "include/numeric.hxx"


int main()
{
  std::vector<double> v(8);

  cmb::iota(v.begin(), v.end(), -4.5);

  for (auto i : v)
    std::cout << " " << i; // = -4.5 -3.5 -2.5 -1.5 -0.5 0.5 1.5 2.5

  std::cout << std::endl;
}