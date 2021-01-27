#include <iostream>
#include <functional.hxx>


template <typename T, typename L = cmb::logical_and<>>
bool logical_test( T a, T b, L logical = L{ } )
{
  return logical(a, b);
}


int main()
{
  bool r1 = logical_test(true, true );
  bool r2 = logical_test(true, false);

  std::cout <<   "result 1 = " << r1 // = 1
            << "\nresult 2 = " << r2 // = 0
            << std::endl;
}