#include <iostream>
#include <vector>
#include <numeric.hxx>


int main()
{
  std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };

  auto multiply = [ ](auto a, auto b) { return a * b; };

  auto r1 = cmb::accumulate( v.begin(), v.end(), 0 );
  auto r2 = cmb::accumulate( v.begin(), v.end(), 1, multiply );

  std::cout <<   "result 1 = " << r1 // = 36
            << "\nresult 2 = " << r2 // = 40320
            << std::endl;
}