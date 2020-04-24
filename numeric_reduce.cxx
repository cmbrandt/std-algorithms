// numeric_reduce.cxx

#include <iostream>
#include <vector>
#include "include/numeric.hxx"


int main()
{
  std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };

  auto add = [ ](auto a, auto b) { return a + b; };

  auto r1 = cmb::reduce(v.begin(), v.end());
  auto r2 = cmb::reduce(v.begin(), v.end(), 0);
  auto r3 = cmb::reduce(v.begin(), v.end(), 0, add);

  std::cout <<   "result 1 = " << r1 // = 36
            << "\nresult 2 = " << r2 // = 36
            << "\nresult 3 = " << r3 // = 36
            << std::endl;
}