// functional_bit_and.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename B = cmb::bit_and<>>
T bit_test( T a, T b, B bit = B{} )
{ return bit(a, b); }


int main()
{
  std::cout << "bit_test(5, 9) = "
            <<  bit_test(5, 9) // = 1
            << std::endl;
}