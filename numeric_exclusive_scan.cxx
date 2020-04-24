// numeric_exclusive_scan.cxx
#include <numeric>
#include <iostream>
#include <vector>
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<int> x{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> y(8);

  std::exclusive_scan(x.begin(), x.end(), y.begin(), 0);

  for (auto i : y)
    std::cout << " " << i; // = 0 3 4 8 9 14 23 25

  std::cout << std::endl;


  std::exclusive_scan(x.begin(), x.end(), y.begin(), 1, cmb::multiplies<>{});

  for (auto i : y)
    std::cout << " " << i; // = 1 3 3 12 12 60 540 1080

  std::cout << std::endl;

  
}