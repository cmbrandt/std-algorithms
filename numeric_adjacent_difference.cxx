// numeric_adjacent_difference.cxx

#include <iostream>
#include <vector>
#include "include/numeric.hxx"


int main()
{
  std::vector<int> v{ 2, 4, 6, 8, 10, 12 };
  std::vector<int> x(6);
  std::vector<int> y(6);

  auto multiply = [ ](auto a, auto b) { return a * b; };

  cmb::adjacent_difference( v.begin(), v.end(), x.begin() );
  cmb::adjacent_difference( v.begin(), v.end(), y.begin(), multiply );

  for (auto i : x)
    std::cout << " " << i; // = 2 2 2 2 2 2

  std::cout << std::endl;

  for (auto i : y)
    std::cout << " " << i; // = 2 8 24 48 80 120

  std::cout << std::endl;
}