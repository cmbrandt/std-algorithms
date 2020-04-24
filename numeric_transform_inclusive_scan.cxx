// numeric_transform_inclusive_scan.cxx
#include <numeric>
#include <iostream>
#include <vector>
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<int> x{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> y(8);

  auto times_10 = [](auto x) { return x * 10; };


  cmb::transform_inclusive_scan(x.begin(), x.end(), y.begin(), cmb::plus<>{}, times_10);

  for (auto i : y)
    std::cout << " " << i; // = 30 40 80 90 140 230 250 310

  std::cout << std::endl;


  cmb::transform_inclusive_scan(x.begin(), x.end(), y.begin(), cmb::plus<>{}, times_10, 0);

  for (auto i : y)
    std::cout << " " << i; // = 30 40 80 90 140 230 250 310

  std::cout << std::endl;
}