// functional_less.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::less<T>>
bool compare_test(T a, T b, C compare = C())
{
  return compare(a, b);
}

// NOTE: The full implementation of less does not require the explicit
//       template parameter T.. something to dig into later on.


int main()
{
  std::cout <<   "compare_test(0,   5  ) = " << compare_test(0,   5  )
            << "\ncompare_test(5.0, 0.0) = " << compare_test(5.0, 0.0)
            << std::endl;
}