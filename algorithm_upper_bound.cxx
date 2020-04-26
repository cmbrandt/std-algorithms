// algorithm_upper_bound.cxx

#include <iostream>
#include <vector>
#include "include/algorithm.hxx"


int main()
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int v = 4;
  
  auto less = [ ](auto a, auto b) { return a < b; };

  auto i1 = cmb::upper_bound( x.begin(), x.end(), v );
  auto i2 = cmb::upper_bound( x.begin(), x.end(), v, less );

  std::cout <<   "upper bound 1 = " << ( i1 - x.begin() ) // = 6
            << "\nupper bound 2 = " << ( i2 - x.begin() ) // = 6
            << std::endl;
}