// functional_logical_and.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename L = cmb::logical_and<>>
T logical_test( T a, T b, L logical = L{} )
{ return logical(a, b); }


int main()
{
  std::cout <<   "logical_test(true, true ) = "
            <<    logical_test(true, true ) // = 1
            << "\nlogical_test(true, false) = "
            <<    logical_test(true, false) // = 0
            << std::endl;
}