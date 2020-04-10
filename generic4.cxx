// generic4.cxx

// g++-9 -std=c++17 -Wall generic4.cxx lower_bound_concrete.cxx -o g4

#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
#include "lower_bound_generic.hxx"


int main()
{
  std::vector<double> x =
    { 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0, 4.0, 5.0, 5.0, 6.0, 6.0 };

  double v = 4.0;

  auto s = lower_bound_generic_3(x.begin(), x.end(), v);

  std::cout << "s = " << std::distance( x.begin(), s )  << std::endl;
}