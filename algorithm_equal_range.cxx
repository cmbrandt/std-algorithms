#include <iostream>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int v = 4;
  
  auto less = [ ](auto a, auto b) { return a < b; };

  auto r1 = cmb::equal_range( x.begin(), x.end(), v );
  auto r2 = cmb::equal_range( x.begin(), x.end(), v, less );

  std::cout <<   "lower bound 1 = " << ( r1.first  - x.begin() ) // = 6
            << "\nupper bound 1 = " << ( r1.second - x.begin() ) // = 8
            << "\nlower bound 2 = " << ( r2.first  - x.begin() ) // = 6
            << "\nupper bound 2 = " << ( r2.second - x.begin() ) // = 8
            << std::endl;
}