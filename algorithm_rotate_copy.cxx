#include <iostream>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<int> v{ 1, 2, 3, 4, 5 };
  std::vector<int> s(5);

  cmb::rotate_copy( v.begin(), v.begin() + 3, v.end(), s.begin() );
  
  for (auto i : v)
    std::cout << " " << i; // = 1, 2, 3, 4, 5

  std::cout << std::endl;

  for (auto i : s)
    std::cout << " " << i; // = 4, 5, 1, 2, 3

  std::cout << std::endl;
}