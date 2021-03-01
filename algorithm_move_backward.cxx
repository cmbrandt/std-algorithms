#include <iostream>
#include <string>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<std::string> v{ "abc", "def", "uvw", "xyz"               };
  std::vector<std::string> s{ "aaa", "bbb", "ccc", "ddd", "eee", "fff" };

  cmb::move_backward( v.begin(), v.end(), s.end() );

  for (auto const& i : v)
    std::cout << " " << i; // = 

  std::cout << std::endl;

  for (auto const& i : s)
    std::cout << " " << i; // = "aaa" "bbb" "abc" "def" "uvw" "xyz"

  std::cout << std::endl;
}