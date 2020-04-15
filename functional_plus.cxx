// functional_plus.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"


template <typename T,
          typename C = cmb::plus<>>
T arithmetic_test(T a, T b, C arithmetic = C())
{
  return arithmetic(a, b);
}


int main()
{
  std::cout <<   "arithmetic_test(1,   2  ) = "
            <<    arithmetic_test(1,   2  ) // = 3
            << "\narithmetic_test(1.2, 2.5) = "
            <<    arithmetic_test(1.2, 2.5) // = 3.7
            << std::endl;
}

/*

g++-9 -Wall -std=c++17 functional_plus.cxx       -I /Users/cmbrandt/projects/stl-algorithms/include -o a1
g++-9 -Wall -std=c++17 functional_minus.cxx      -I /Users/cmbrandt/projects/stl-algorithms/include -o a2
g++-9 -Wall -std=c++17 functional_multiplies.cxx -I /Users/cmbrandt/projects/stl-algorithms/include -o a3
g++-9 -Wall -std=c++17 functional_divides.cxx    -I /Users/cmbrandt/projects/stl-algorithms/include -o a4
g++-9 -Wall -std=c++17 functional_modulus.cxx    -I /Users/cmbrandt/projects/stl-algorithms/include -o a5
g++-9 -Wall -std=c++17 functional_negate.cxx     -I /Users/cmbrandt/projects/stl-algorithms/include -o a6

*/