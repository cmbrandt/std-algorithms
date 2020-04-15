// functional_greater_equal.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::greater_equal<>>
bool compare_test(T a, T b, C compare = C())
{
  return compare(a, b);
}


int main()
{
  std::cout <<   "compare_test(0,   5  ) = " << compare_test(0,   5  ) // = 0
            << "\ncompare_test(0.0, 0.0) = " << compare_test(0.0, 0.0) // = 1
            << std::endl;
}