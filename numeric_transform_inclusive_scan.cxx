#include <iostream>
#include <vector>
#include <numeric.hxx>


int main()
{
  std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> x(8);
  std::vector<int> y(8);

  auto add      = [ ](auto a, auto b) { return a + b;  };
  auto times_10 = [ ](auto a)         { return a * 10; };

  cmb::transform_inclusive_scan( v.begin(), v.end(), x.begin(), add, times_10 );
  cmb::transform_inclusive_scan( v.begin(), v.end(), y.begin(), add, times_10, 0 );

  for (auto i : x)
    std::cout << " " << i; // = 30 40 80 90 140 230 250 310

  std::cout << std::endl;

  for (auto i : y)
    std::cout << " " << i; // = 30 40 80 90 140 230 250 310

  std::cout << std::endl;
}