// functional_not_equal_to.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::not_equal_to<>>
bool compare_test( T a, T b, C compare = C{} )
{ return compare(a, b); }


int main()
{
  bool r1 = compare_test(0,   5  );
  bool r2 = compare_test(0.0, 0.0);

  std::cout <<   "result 1 = " << r1 // = 1
            << "\nresult 2 = " << r2 // = 0
            << std::endl;
}