// functional_negate.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T, typename A = cmb::negate<>>
T arithmetic_test( T a, A arithmetic = A{ } )
{
  return arithmetic(a);
}


int main()
{
  auto r1 = arithmetic_test(1  );
  auto r2 = arithmetic_test(1.2);

  std::cout <<   "result 1 = " << r1 // = -1
            << "\nresult 2 = " << r2 // = -1.2
            <<std::endl;
}