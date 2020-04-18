// numeric_accumulate.cxx

#include <iostream>
#include <vector>
#include <numeric> // REMOVE
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };

  auto sum  = std::accumulate(v.begin(), v.end(), 0);
  auto prod = std::accumulate(v.begin(), v.end(), 1, cmb::multiplies<>{ });

  std::cout << "\nsum  = " << sum  // = 36
            << "\nprod = " << prod // = 40320
            << std::endl;
}