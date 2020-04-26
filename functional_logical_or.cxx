// functional_logical_or.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename L = cmb::logical_or<>>
bool logical_test( T a, T b, L logical = L{} )
{ return logical(a, b); }


int main()
{
  bool r1 = logical_test(false, false);
  bool r2 = logical_test(true,  false);

  std::cout <<   "result 1 = " << r1 // = 0
            << "\nresult 2 = " << r2 // = 1
            << std::endl;
}