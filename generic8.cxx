// generic8.cxx

// g++-9 -std=c++17 -Wall generic8.cxx -o g8

#include <algorithm>
#include <iostream>
#include <vector>
#include "binary_search.hxx"
#include "equal_range.hxx"
#include "lower_bound.hxx"
#include "upper_bound.hxx"


int main()
{
  std::vector<int> v = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  auto s1 = std::lower_bound(   v.begin(), v.end(), 4 );
  auto s2 = std::upper_bound(   v.begin(), v.end(), 4 );
  auto s3 = std::binary_search( v.begin(), v.end(), 4 );
  auto s4 = std::equal_range(   v.begin(), v.end(), 4 );

  std::cout << "\nStandard Libary routines:"
            << "\ns1        = " << ( s1 - v.begin() )
            << "\ns2        = " << ( s2 - v.begin() )
            << "\ns3        = " << s3
            << "\ns4.first  = " << s4.first  - v.begin()
            << "\ns4.second = " << s4.second - v.begin()
            << std::endl;

  auto s5 = nag::lower_bound(   v.begin(), v.end(), 4 );
  auto s6 = nag::upper_bound(   v.begin(), v.end(), 4 );
  auto s7 = nag::binary_search( v.begin(), v.end(), 4 );
  auto s8 = nag::equal_range(   v.begin(), v.end(), 4 );

  std::cout << "\nHanded-coded routines:"
            << "\ns5        = " << ( s5 - v.begin() )
            << "\ns6        = " << ( s6 - v.begin() )
            << "\ns7        = " << s7
            << "\ns8.first  = " << s8.first  - v.begin()
            << "\ns8.second = " << s8.second - v.begin()
            << std::endl;
}