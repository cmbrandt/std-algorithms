// numeric_inclusive_scan.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<int> x{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> y(8);


  cmb::inclusive_scan(x.begin(), x.end(), y.begin());

  for (auto i : y)
    std::cout << " " << i; // = 3 4 8 9 14 23 25 31

  std::cout << std::endl;


  cmb::inclusive_scan(x.begin(), x.end(), y.begin(), cmb::multiplies<>{});

  for (auto i : y)
    std::cout << " " << i; // = 3 3 12 12 60 540 1080 6480

  std::cout << std::endl;


  cmb::inclusive_scan(x.begin(), x.end(), y.begin(), cmb::multiplies<>{}, 1);

  for (auto i : y)
    std::cout << " " << i; // = 3 3 12 12 60 540 1080 6480

  std::cout << std::endl;
}