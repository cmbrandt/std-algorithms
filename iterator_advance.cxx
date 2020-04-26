// iterator_advance.cxx

#include <iostream>
#include <vector>
#include "include/iterator.hxx"


int main()
{
  std::vector<int> v{ 1, 2, 3 };

  auto r = v.begin();

  cmb::advance(r, 2);

  std::cout << "*result = " << *r << std::endl; // = 3
}