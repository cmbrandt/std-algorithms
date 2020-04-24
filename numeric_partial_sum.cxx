// numeric_partial_sum.cxx

#include <iostream>
#include <vector>
#include "include/numeric.hxx"


int main()
{
  std::vector<int> v(8, 2);
  std::vector<int> x(8);
  std::vector<int> y(8);

  auto multiply = [ ](auto a, auto b) { return a * b; };

  cmb::partial_sum(v.begin(), v.end(), x.begin());
  cmb::partial_sum(v.begin(), v.end(), y.begin(), multiply);

  for (auto i : x)
    std::cout << " " << i; // = 2 4 6 8 10 12 14 16

  std::cout << std::endl;

  for (auto i : y)
    std::cout << " " << i; // = 2 4 8 16 32 64 128 256

  std::cout << std::endl; 
}