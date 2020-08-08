// functional_logical_not.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T, typename L = cmb::logical_not<>>
bool logical_test( T a, L logical = L{} )
{
  return logical(a);
}


int main()
{
  bool r1 = logical_test(true );
  bool r2 = logical_test(false);

  std::cout <<   "result 1 = " << r1 // = 0
            << "\nresult 2 = " << r2 // = 1
            << std::endl;
}