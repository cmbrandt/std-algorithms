// functional_negate.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::negate<>>
T arithmetic_test(T a, C arithmetic = C())
{ return arithmetic(a); }


int main()
{
  std::cout <<   "arithmetic_test(1  ) = "
            <<    arithmetic_test(1  ) // = -1
            << "\narithmetic_test(1.2) = "
            <<    arithmetic_test(1.2) // = -1.2
            << std::endl;
}