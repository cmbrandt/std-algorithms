// functional_multiplies.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T, typename A = cmb::multiplies<>>
T arithmetic_test( T a, T b, A arithmetic = A{ } )
{
  return arithmetic(a, b);
}


int main()
{
  auto r1 = arithmetic_test(6,   2  );
  auto r2 = arithmetic_test(3.5, 2.5);

  std::cout <<   "result 1 = " << r1 // = 12
            << "\nresult 2 = " << r2 // = 8.75
            <<std::endl;
}