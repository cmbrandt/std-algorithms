// functional_modulus.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::modulus<>>
T arithmetic_test(T a, T b, C arithmetic = C())
{
  return arithmetic(a, b);
}


int main()
{
  std::cout <<   "arithmetic_test(7, 4) = "
            <<    arithmetic_test(7, 4) // = 3
            << std::endl;
}