// numeric_adjacent_difference.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<int> x{ 2, 4, 6, 8, 10, 12 };
  std::vector<int> y(6);
  std::vector<int> z(6);

  cmb::adjacent_difference( x.begin(), x.end(), y.begin() );
  cmb::adjacent_difference( x.begin(), x.end(), y.begin(), cmb::multiplies<>{} );

  for (auto i : y)
    std::cout << " " << i; // = 2 2 2 2 2 2

  std::cout << std::endl;

  for (auto i : z)
    std::cout << " " << i; // = 2 8 24 48 80 120

  std::cout << std::endl;
}