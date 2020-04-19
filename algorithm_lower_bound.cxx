// algorithm_lower_bound.cxx

#include <iostream>
#include <vector>
#include "include/algorithm.hxx"


int main()
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int v = 4;
  
  auto i1 = cmb::lower_bound(x.begin(), x.end(), v);
  auto i2 = cmb::lower_bound(x.begin(), x.end(), v, cmb::less<>{ });

  std::cout <<   "lower bound 1 = " << ( i1 - x.begin() ) // = 6
            << "\nlower bound 2 = " << ( i2 - x.begin() ) // = 6
            << std::endl;
}