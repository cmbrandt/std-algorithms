// functional_logical_not.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename L = cmb::logical_not<>>
T logical_test( T a, L logical = L{} )
{ return logical(a); }


int main()
{
  std::cout <<   "logical_test(true ) = "
            <<    logical_test(true ) // = 0
            << "\nlogical_test(false) = "
            <<    logical_test(false) // = 1
            << std::endl;
}