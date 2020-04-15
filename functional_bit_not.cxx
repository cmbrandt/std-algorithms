// functional_bit_not.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::bit_not<>>
T bit_test(T a, C bit = C())
{ return bit(a); }


int main()
{
  std::cout << "bit_test(5) = "
            <<  bit_test(5) // = -6
            << std::endl;
}