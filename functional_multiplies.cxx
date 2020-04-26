// functional_multiplies.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename A = cmb::multiplies<>>
T arithmetic_test( T a, T b, A arithmetic = A{} )
{ return arithmetic(a, b); }


int main()
{
  std::cout <<   "arithmetic_test(6,   2  ) = "
            <<    arithmetic_test(6,   2  ) // = 12
            << "\narithmetic_test(3.5, 2.5) = "
            <<    arithmetic_test(3.5, 2.5) // = 8.75
            << std::endl;
}