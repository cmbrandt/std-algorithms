// algorithm_upper_bound.cxx

#include <iostream>
#include <vector>
#include "include/algorithm.hxx"


int main()
{
  std::vector<int> x = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int v = 4;
  
  auto it = cmb::upper_bound(x.begin(), x.end(), v);

  std::cout << "upper bound = " << ( it - x.begin() ) << std::endl; // = 8
}