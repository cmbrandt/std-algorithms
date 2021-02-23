#include <iostream>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<int> v{ 1, 2, 3, 4 };
  std::vector<int> s{ 0, 0, 0, 0 };

  cmb::swap_ranges( v.begin(), v.end(), s.begin() );

  for (auto i : v)
    std::cout << " " << i; // = 0 0 0 0

  std::cout << std::endl;

  for (auto i : s)
    std::cout << " " << i; // = 1 2 3 4

  std::cout << std::endl;
}