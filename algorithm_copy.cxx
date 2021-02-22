#include <iostream>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7 };
  std::vector<int> s(8);

  cmb::copy( v.begin(), v.end(), s.begin() );

  for (auto i : v)
    std::cout << " " << i; // = 0 1 2 3 4 5 6 7

  std::cout << std::endl;

  for (auto i : s)
    std::cout << " " << i; // = 0 1 2 3 4 5 6 7

  std::cout << std::endl;
}