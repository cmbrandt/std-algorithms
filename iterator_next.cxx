// iterator_next.cxx

#include <iostream>
#include <vector>
#include "include/iterator.hxx"


int main()
{
  std::vector<int> v{ 1, 2, 3};

  auto it = v.begin();

  auto nx = cmb::next(it, 2);

  std::cout << "*nx = " << *nx << std::endl;
}