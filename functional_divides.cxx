#include <iostream>
#include <functional.hxx>


template <typename T, typename A = cmb::divides<>>
T arithmetic_test( T a, T b, A arithmetic = A{ } )
{
  return arithmetic(a, b);
}


int main()
{
  auto r1 = arithmetic_test(6,   2  );
  auto r2 = arithmetic_test(3.5, 2.5);

  std::cout <<   "result 1 = " << r1 // = 3
            << "\nresult 2 = " << r2 // = 1.4
            <<std::endl;
}