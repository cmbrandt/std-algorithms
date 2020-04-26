// functional_modulus.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename A = cmb::modulus<>>
T arithmetic_test( T a, T b, A arithmetic = A{} )
{ return arithmetic(a, b); }


int main()
{
  std::cout <<   "arithmetic_test(7, 4) = "
            <<    arithmetic_test(7, 4) // = 3
            << std::endl;
}