// functional_bit_and.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T, typename B = cmb::bit_and<>>
T bit_test( T a, T b, B bit = B{ } )
{
  return bit(a, b);
}


int main()
{
  auto r = bit_test(5, 9);

  std::cout << "result = " << r << std::endl; // = 1
}