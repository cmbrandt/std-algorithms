#include <iostream>
#include <functional.hxx>


template <typename T, typename A = cmb::plus<>>
T arithmetic_test( T a, T b, A arithmetic = A{ } )
{
  return arithmetic(a, b);
}


int main()
{
  auto r1 = arithmetic_test(1,   2  );
  auto r2 = arithmetic_test(1.2, 2.5);

  std::cout <<   "result 1 = " << r1 // = 3
            << "\nresult 2 = " << r2 // = 3.7
            <<std::endl;
}