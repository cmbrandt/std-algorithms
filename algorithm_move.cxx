#include <iostream>
#include <string>
#include <vector>
#include <algorithm.hxx>


int main()
{
  std::vector<std::string> v{ "abc", "def", "uvw", "xyz" };
  std::vector<std::string> s(4);

  cmb::move( v.begin(), v.end(), s.begin() );

  for (auto const& i : v)
    std::cout << " " << i; // = 

  std::cout << std::endl;

  for (auto const& i : s)
    std::cout << " " << i; // = "abc" "def" "uvw" "xyz"

  std::cout << std::endl;
}