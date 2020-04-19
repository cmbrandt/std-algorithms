// numeric_inner_product.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<double> a{ 0, 1, 2, 3, 4 };
  std::vector<double> b{ 5, 4, 2, 3, 1 };

  auto r1 = cmb::inner_product(a.begin(), a.end(), b.begin(), 0);

  auto r2 = cmb::inner_product(a.begin(), a.end(), b.begin(), 0,
                               cmb::plus<>{ }, cmb::equal_to<>{ });

  std::cout <<   "result 1 = " << r1 // = 21
            << "\nresult 2 = " << r2 // = 2
            << std::endl;
}