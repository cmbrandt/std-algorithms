// numeric_midpoint.cxx

#include <iostream>
#include <limits>
#include "include/numeric.hxx"


int main()
{
  std::uint32_t a = std::numeric_limits<std::uint32_t>::max();
  std::uint32_t b = std::numeric_limits<std::uint32_t>::max() - 2;
 
  float x = std::numeric_limits<float>::max();
  float y = std::numeric_limits<float>::max() - 2;

  auto i1 = (a + b) / 2;
  auto i1 = (x + y) / 2;

  auto c1 = cmb::midpoint(a, b);
  auto c2 = cmb::midpoint(x, y);

  std::cout << "\nIncorrect " << i1 // =  (wrapping)
            << "\nCorrect:  " << c1 // = 
            << std::endl;

  std::cout << "\nIncorrect " << i2 // = (overflow)
            << "\nCorrect:  " << c2 // = 
            << std::endl;
}