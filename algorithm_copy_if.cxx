#include <iostream>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7 };
  std::vector<int> s(4);

  auto odd = [](int x) { return (x % 2) == 1; };

  cmb::copy_if(v.begin(), v.end(), s.begin(), odd);

  for (auto i : s)
    std::cout << " " << i; // = 1, 3, 5, 7

  std::cout << std::endl;
}