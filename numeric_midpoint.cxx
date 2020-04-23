// numeric_midpoint.cxx
#include <numeric>
#include <iostream>
#include <limits>
#include "include/numeric.hxx"


//
// UPDATE THIS EXAMPLE LATER ON !!!
//


int main()
{
  // Integral types

  std::int32_t a = std::numeric_limits<std::int32_t>::max();
  std::int32_t b = std::numeric_limits<std::int32_t>::max() - 2;
 
  std::cout << "\nUsing std::uint32_t:"
            << "\na: " << a
            << "\nb: " << b
            << "\nIncorrect (overflow and wrapping): " << (a + b) / 2
            << "\nCorrect: " << cmb::midpoint(a, b) << std::endl;

  // Floating-point types

  float x = std::numeric_limits<float>::max();
  float y = std::numeric_limits<float>::max() - 2;
 
  std::cout << "\nUsing float:"
            << "\nIncorrect (overflow and wrapping): " << (x + y) / 2
            << "\nCorrect: " << cmb::midpoint(x, y) << std::endl;
}