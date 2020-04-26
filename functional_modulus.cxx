// functional_modulus.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename A = cmb::modulus<>>
T arithmetic_test( T a, T b, A arithmetic = A{} )
{ return arithmetic(a, b); }


int main()
{
  auto r1 = arithmetic_test(7, 4);
  auto r2 = arithmetic_test(8, 2);

  std::cout <<   "result 1 = " << r1 // = 3
            << "\nresult 2 = " << r2 // = 0
            <<std::endl;
}