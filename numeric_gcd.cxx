#include <iostream>
#include <numeric.hxx>


int main()
{
  int m = 8;
  int n = 12;

  auto r = cmb::gcd(m, n);

  std::cout << "result = " << r << std::endl; // = 4
}