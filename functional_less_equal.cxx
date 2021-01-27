#include <iostream>
#include <functional.hxx>


template <typename T, typename C = cmb::less_equal<>>
bool compare_test( T a, T b, C compare = C{ } )
{
  return compare(a, b);
}


int main()
{
  bool r1 = compare_test(5,   0  );
  bool r2 = compare_test(0.0, 0.0);

  std::cout <<   "result 1 = " << r1 // = 0
            << "\nresult 2 = " << r2 // = 1
            << std::endl;
}