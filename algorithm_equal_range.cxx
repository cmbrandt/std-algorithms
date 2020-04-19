// algorithm_equal_range.cxx

#include <iostream>
#include <vector>
#include "include/algorithm.hxx"


int main()
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int v = 4;
  
  auto r1 = cmb::equal_range(x.begin(), x.end(), v);
  auto r2 = cmb::equal_range(x.begin(), x.end(), v, cmb::less<>{ });

  std::cout <<   "lower bound 1 = " << ( r1.first  - x.begin() ) // = 6
            << "\nupper bound 1 = " << ( r1.second - x.begin() ) // = 8
            << "\nlower bound 2 = " << ( r2.first  - x.begin() ) // = 6
            << "\nupper bound 2 = " << ( r2.second - x.begin() ) // = 8
            << std::endl;
}