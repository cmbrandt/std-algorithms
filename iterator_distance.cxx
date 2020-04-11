// iterator_distance.cxx

#include <iostream>
#include <vector>
#include "include/iterator.hxx"


int main()
{
  std::vector<int> v{ 1, 2, 3 };

  std::cout << "cmb::distance(first, last) = "
            <<  cmb::distance(v.begin(), v.end()) << std::endl;
}