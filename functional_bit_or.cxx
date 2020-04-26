// functional_bit_or.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename B = cmb::bit_or<>>
T bit_test( T a, T b, B bit = B{} )
{ return bit(a, b); }


int main()
{
  auto r = bit_test(5, 9);

  std::cout << "result = " << r << std::endl; // = 13
}