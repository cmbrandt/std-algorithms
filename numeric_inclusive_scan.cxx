#include <iostream>
#include <vector>
#include <numeric.hxx>


int main()
{
  std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> x(8);
  std::vector<int> y(8);
  std::vector<int> z(8);

  auto multiply = [ ](auto a, auto b) { return a * b; };

  cmb::inclusive_scan( v.begin(), v.end(), x.begin() );
  cmb::inclusive_scan( v.begin(), v.end(), y.begin(), multiply );
  cmb::inclusive_scan( v.begin(), v.end(), z.begin(), multiply, 1 );

  for (auto i : x)
    std::cout << " " << i; // = 3 4 8 9 14 23 25 31

  std::cout << std::endl;

  for (auto i : y)
    std::cout << " " << i; // = 3 3 12 12 60 540 1080 6480

  std::cout << std::endl;

  for (auto i : z)
    std::cout << " " << i; // = 3 3 12 12 60 540 1080 6480

  std::cout << std::endl;
}