// generic3.cxx

// g++-9 -std=c++17 -Wall generic3.cxx lower_bound_concrete.cxx -o g3

#include <cstdint>
#include <iostream>
#include <vector>
#include "lower_bound_generic.hxx"


int main()
{
  std::vector<double> x =
    { 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0, 4.0, 5.0, 5.0, 6.0, 6.0 };

  std::uint32_t n = x.size();
  double        v = 4.0;

  auto s = lower_bound_generic_2(x.data(), n, v);

  std::cout << "s = " << s << std::endl;
}