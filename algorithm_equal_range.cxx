// algorithm_equal_range.cxx

#include <iostream>
#include <vector>
#include "include/algorithm.hxx"


int main()
{
  std::vector<int> x = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int v = 4;
  
  auto range = cmb::equal_range(x.begin(), x.end(), v);

  std::cout <<   "lower bound = " << ( range.first  - x.begin() ) // = 6
            << "\nupper bound = " << ( range.second - x.begin() ) // = 8
            << std::endl;
}