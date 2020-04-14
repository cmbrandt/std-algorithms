// functional_equal_to.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::equal_to<>>
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

/*

g++-9 -Wall -std=c++17 functional_equal_to.cxx      -I /Users/cmbrandt/projects/stl-algorithms -o a1
g++-9 -Wall -std=c++17 functional_not_equal_to.cxx  -I /Users/cmbrandt/projects/stl-algorithms -o a2
g++-9 -Wall -std=c++17 functional_greater.cxx       -I /Users/cmbrandt/projects/stl-algorithms -o a3
g++-9 -Wall -std=c++17 functional_greater_equal.cxx -I /Users/cmbrandt/projects/stl-algorithms -o a4
g++-9 -Wall -std=c++17 functional_less.cxx          -I /Users/cmbrandt/projects/stl-algorithms -o a5
g++-9 -Wall -std=c++17 functional_less_equal.cxx    -I /Users/cmbrandt/projects/stl-algorithms -o a6

*/