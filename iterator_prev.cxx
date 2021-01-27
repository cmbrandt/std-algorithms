#include <iostream>
#include <vector>
#include <iterator.hxx>


int main()
{
  std::vector<int> v{ 1, 2, 3 };

  auto i = v.end();

  auto r = cmb::prev(i, 2);

  std::cout << "*result = " << *r << std::endl; // = 2
}