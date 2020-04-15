// functional_logical_or.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::logical_or<>>
T logical_test(T a, T b, C logical = C())
{ return logical(a, b); }


int main()
{
  std::cout <<   "logical_test(false, false) = "
            <<    logical_test(false, false) // = 0
            << "\nlogical_test(true,  false) = "
            <<    logical_test(true,  false) // = 1
            << std::endl;
}