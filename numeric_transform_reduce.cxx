// numeric_transform_reduce.cxx

#include <iostream>
#include <vector>
#include "include/functional.hxx"
#include "include/numeric.hxx"


int main()
{
  std::vector<double> x(10007, 1.0);
  std::vector<double> y(10007, 1.0);

  auto r1 = cmb::transform_reduce(x.begin(), x.end(), 0, cmb::plus<>{ },
                                  cmb::negate<>{ });

  auto r2 = cmb::transform_reduce(x.begin(), x.end(), y.begin(), 0);

  auto r3 = cmb::transform_reduce(x.begin(), x.end(), y.begin(), 0,
                                  cmb::minus<>{ }, cmb::multiplies<> { });

  std::cout <<   "result 1 = " << r1 // = -10007
            << "\nresult 2 = " << r2 // =  10007
            << "\nresult 3 = " << r3 // = -10007
            << std::endl;
}