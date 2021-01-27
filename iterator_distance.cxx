#include <iostream>
#include <vector>
#include <iterator.hxx>


int main()
{
  std::vector<int> v{ 1, 2, 3 };

  auto r = cmb::distance( v.begin(), v.end() );

  std::cout << "result = " << r << std::endl; // = 3
}