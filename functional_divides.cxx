// functional_divides.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::divides<>>
T arithmetic_test(T a, T b, C arithmetic = C())
{
  return arithmetic(a, b);
}


int main()
{
  std::cout <<   "arithmetic_test(6,   2  ) = "
            <<    arithmetic_test(6,   2  ) // = 3
            << "\narithmetic_test(3.5, 2.5) = "
            <<    arithmetic_test(3.5, 2.5) // = 1.4
            << std::endl;
}