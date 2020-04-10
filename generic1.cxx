// generic1.cxx

// g++-9 -std=c++17 -Wall generic1.cxx lower_bound_concrete.cxx -o g1

#include <iostream>
#include <vector>
#include "lower_bound_concrete.hxx"


int main()
{
  std::vector<int> x = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int n = 12;
  int v = 4;
  
  auto s = lower_bound_concrete(x.data(), n, v);

  std::cout << "s = " << s << std::endl;
}