// algorithm_binary_search.cxx

#include <algorithm>
#include <iostream>
#include <vector>
#include "include/algorithm.hxx"


struct comp {
  template <typename T1, typename T2 = T1>
  inline bool  
  operator()(T1 const& a, T2 const& b) const { return a < b; }
  using is_transparent = void;
};


int main()
{
  std::vector<int> x = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  int v = 4;
  
  auto result = cmb::binary_search(x.begin(), x.end(), v);

  std::cout << "result = " << result << std::endl; // = 1
}