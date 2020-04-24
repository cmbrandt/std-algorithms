// numeric_partial_sum.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<int> x(8, 2);
  std::vector<int> y(8);


  cmb::partial_sum( x.begin(), x.end(), y.begin() );

  for (auto i : y)
    std::cout << " " << i;

  std::cout << std::endl;


  cmb::partial_sum( x.begin(), x.end(), y.begin(), cmb::multiplies<>{} );

  for (auto i : y)
    std::cout << " " << i;

  std::cout << std::endl; 
}