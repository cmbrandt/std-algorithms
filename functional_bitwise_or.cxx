// functional_bit_or.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::bit_or<>>
T bit_test(T a, T b, C bit = C())
{ return bit(a, b); }


int main()
{
  std::cout << "bit_test(5, 9) = "
            <<  bit_test(5, 9) // = 13
            << std::endl;
}