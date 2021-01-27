#include <iostream>
#include <vector>
#include <numeric.hxx>


int main()
{
  std::vector<double> x{ 0, 1, 2, 3, 4 };
  std::vector<double> y{ 5, 4, 2, 3, 1 };

  auto add   = [ ](auto a, auto b) { return a + b;  };
  auto equal = [ ](auto a, auto b) { return a == b; };

  auto r1 = cmb::inner_product( x.begin(), x.end(), y.begin(), 0 );
  auto r2 = cmb::inner_product( x.begin(), x.end(), y.begin(), 0, add, equal );

  std::cout <<   "result 1 = " << r1 // = 21
            << "\nresult 2 = " << r2 // = 2
            << std::endl;
}