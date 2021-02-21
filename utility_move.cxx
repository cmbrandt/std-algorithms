#include <iostream>
#include <string>
#include <vector>
#include <utility.hxx>


int main()
{
  std::string str = "xyz";
  std::vector<std::string> v;
 
  v.push_back(str);
  std::cout << "str = " << str << std::endl; // = "xyz"

  v.push_back( cmb::move(str) );
  std::cout << "str = " << str << std::endl; // =
 
  for (auto const& i : v)
    std::cout << " " << i; // = "xyz" "xyz"

  std::cout << std::endl;
}