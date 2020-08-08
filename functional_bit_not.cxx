// functional_bit_not.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T, typename B = cmb::bit_not<>>
T bit_test( T a, B bit = B{ } )
{
  return bit(a);
}


int main()
{
  auto r = bit_test(5);

  std::cout << "result = " << r << std::endl; // = -6
}