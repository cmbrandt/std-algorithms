#include <iostream>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<int> v{ 1, 2, 3, 4 };
  std::vector<int> s{ 0, 0, 0, 0 };

  cmb::iter_swap( v.begin(), s.begin() + 2 );

  for (auto i : v)
    std::cout << " " << i; // = 0 2 3 4

  std::cout << std::endl;

  for (auto i : s)
    std::cout << " " << i; // = 0 0 1 0

  std::cout << std::endl;
}