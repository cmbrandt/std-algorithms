#include <iostream>
#include <vector>
#include <numeric.hxx>


int main()
{
  std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> x(8);

  auto add      = [ ](auto a, auto b) { return a + b;  };
  auto times_10 = [ ](auto a)         { return a * 10; };

  cmb::transform_exclusive_scan( v.begin(), v.end(), x.begin(), 0, add, times_10 );

  for (auto i : x)
    std::cout << " " << i; // = 0 30 40 80 90 140 230 250

  std::cout << std::endl;
}