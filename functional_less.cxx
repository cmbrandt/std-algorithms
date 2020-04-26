// functional_less.cxx

#include <iostream>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::less<>>
bool compare_test( T a, T b, C compare = C{} )
{ return compare(a, b); }


int main()
{
  std::cout <<   "compare_test(5,   0  ) = "
            <<    compare_test(5,   0  ) // = 0
            << "\ncompare_test(0.0, 5.0) = "
            <<    compare_test(0.0, 5.0) // = 1
            << std::endl;
}