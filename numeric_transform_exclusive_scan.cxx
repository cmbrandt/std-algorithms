// numeric_transform_exclusive_scan.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<int> x{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> y(8);

  auto times_10 = [ ](auto x) { return x * 10; };


  std::transform_exclusive_scan(x.begin(), x.end(), y.begin(), 0,
                                cmb::plus<>{}, times_10);

  for (auto i : y)
    std::cout << " " << i; // = 0 30 40 80 90 140 230 250

  std::cout << std::endl;
}