// functional_minus.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename A = cmb::minus<>>
T arithmetic_test( T a, T b, A arithmetic = A{} )
{ return arithmetic(a, b); }


int main()
{
  std::cout <<   "arithmetic_test(1,   2  ) = "
            <<    arithmetic_test(1,   2  ) // = -1
            << "\narithmetic_test(1.2, 2.5) = "
            <<    arithmetic_test(1.2, 2.5) // = -1.3
            << std::endl;
}