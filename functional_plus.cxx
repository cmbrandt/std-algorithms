// functional_plus.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::plus<>>
T arithmetic_test(T a, T b, C arithmetic = C())
{ return arithmetic(a, b); }


int main()
{
  std::cout <<   "arithmetic_test(1,   2  ) = "
            <<    arithmetic_test(1,   2  ) // = 3
            << "\narithmetic_test(1.2, 2.5) = "
            <<    arithmetic_test(1.2, 2.5) // = 3.7
            << std::endl;
}