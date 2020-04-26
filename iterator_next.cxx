// iterator_next.cxx

#include <iostream>
#include <vector>
#include "include/iterator.hxx"


int main()
{
  std::vector<int> v{ 1, 2, 3 };

  auto i = v.begin();

  auto r = cmb::next(i, 2);

  std::cout << "*result = " << *r << std::endl; // = 3
}