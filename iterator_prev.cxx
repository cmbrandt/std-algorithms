// iterator_next.cxx

#include <iostream>
#include <vector>
#include "include/iterator.hxx"


int main()
{
  std::vector<int> v{ 1, 2, 3 };

  auto it = v.end();

  auto pv = cmb::prev(it, 2);

  std::cout << "*pv = " << *pv << std::endl;
}