// iterator_advance.cxx

#include <iostream>
#include <vector>
#include "include/iterator.hxx"


int main()
{
  std::vector<int> v{ 1, 2, 3 };

  auto it = v.begin();

  cmb::advance(it, 2);

  std::cout << "*it = " << *it << std::endl; // = 3
}