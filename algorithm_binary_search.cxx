// algorithm_binary_search.cxx

#include <iostream>
#include <vector>
#include "include/algorithm.hxx"


int main()
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int v = 4;
  
  auto less = [ ](auto a, auto b) { return a < b; };

  auto r1 = cmb::binary_search( x.begin(), x.end(), v );
  auto r2 = cmb::binary_search( x.begin(), x.end(), v, less );

  std::cout <<   "result 1 = " << r1 // = 1
            << "\nresult 2 = " << r2 // = 1
            << std::endl;
}