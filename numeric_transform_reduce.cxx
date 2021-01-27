#include <iostream>
#include <vector>
#include <numeric.hxx>


int main()
{
  std::vector<double> x(10007, 1.0);
  std::vector<double> y(10007, 1.0);

  auto add = [ ](auto a, auto b) { return a + b; };
  auto sub = [ ](auto a, auto b) { return a - b; };
  auto mul = [ ](auto a, auto b) { return a * b; };
  auto neg = [ ](auto a)         { return -a;    };

  auto r1 = cmb::transform_reduce( x.begin(), x.end(), y.begin(), 0 );
  auto r2 = cmb::transform_reduce( x.begin(), x.end(), y.begin(), 0, sub, mul );
  auto r3 = cmb::transform_reduce( x.begin(), x.end(), 0, add, neg );

  std::cout <<   "result 1 = " << r1 // =  10007
            << "\nresult 2 = " << r2 // = -10007
            << "\nresult 3 = " << r3 // = -10007
            << std::endl;
}