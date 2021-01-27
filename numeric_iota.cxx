#include <iostream>
#include <vector>
#include <numeric.hxx>


int main()
{
  std::vector<double> v(8);

  cmb::iota( v.begin(), v.end(), -3.5 );

  for (auto i : v)
    std::cout << " " << i; // = -3.5 -2.5 -1.5 -0.5 0.5 1.5 2.5 3.5

  std::cout << std::endl;
}