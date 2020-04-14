// functional_not_equal_to.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::not_equal_to<>>
bool compare_test(T a, T b, C compare = C())
{
  return compare(a, b);
}


int main()
{
  std::cout <<   "compare_test(0,   5  ) = " << compare_test(0,   5  ) // = 1
            << "\ncompare_test(0.0, 0.0) = " << compare_test(0.0, 0.0) // = 0
            << std::endl;
}