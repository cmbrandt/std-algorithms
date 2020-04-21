// numeric_iota.cxx

#include <iostream>
#include <vector>
#include "include/numeric.hxx"


int main()
{
  std::vector<double> v(10);

  cmb::iota(v.begin(), v.end(), -4.5);

  for (auto i : v)
    std::cout << " " << i;

  std::cout << std::endl;
}