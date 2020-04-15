// functional_bitwise_not.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = std::bit_not<>>
T bit_test(T a, C bit = C())
{ return bit(a); }


int main()
{
  std::cout << "bit_test(a) = "
            <<  bit_test(a) // = 250 / -6
            << std::endl;
}