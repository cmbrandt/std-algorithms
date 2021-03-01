#include <iostream>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<int> v{ 1, 2, 3, 4, 5 };

  cmb::rotate( v.begin(), v.begin() + 3, v.end() );
  
  for (auto i : v)
    std::cout << " " << i; // = 4, 5, 1, 2, 3

  std::cout << std::endl;
}