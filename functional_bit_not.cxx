// functional_bit_not.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename B = cmb::bit_not<>>
T bit_test( T a, B bit = B{} )
{ return bit(a); }


int main()
{
  std::cout << "bit_test(5) = "
            <<  bit_test(5) // = -6
            << std::endl;
}