// functional_less_equal.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::less_equal<>>
bool compare_test(T a, T b, C compare = C())
{
  return compare(a, b);
}


int main()
{
  std::cout <<   "compare_test(5,   0  ) = " << compare_test(5,   0  ) // = 1
            << "\ncompare_test(0.0, 0.0) = " << compare_test(0.0, 0.0) // = 0
            << std::endl;
}