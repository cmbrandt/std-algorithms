// functional_logical_and.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::logical_and<>>
T logical_test(T a, T b, C arithmetic = C())
{ return logical(a, b); }


int main()
{
  std::cout <<   "logical_test(1,   2  ) = "
            <<    logical_test(1,   2  ) // = 3
            << "\nlogical_test(1.2, 2.5) = "
            <<    logical_test(1.2, 2.5) // = 3.7
            << std::endl;
}