#include <iostream>
#include <limits>
#include <vector>
#include <numeric.hxx>


int main()
{
  // Arithmetic types

  std::uint32_t a = std::numeric_limits<std::uint32_t>::max();
  std::uint32_t b = std::numeric_limits<std::uint32_t>::max() - 2;

  float x = std::numeric_limits<float>::max();
  float y = std::numeric_limits<float>::max() - 2;

  auto i1 = (a + b) / 2;
  auto i2 = (x + y) / 2;

  auto c1 = cmb::midpoint(a, b);
  auto c2 = cmb::midpoint(x, y);

  std::cout << "\nIncorrect: " << i1 // = 2147483646 (wrapping)
            << "\nCorrect:   " << c1 // = 4294967294
            << std::endl;

  std::cout << "\nIncorrect: " << i2 // = inf (overflow)
            << "\nCorrect:   " << c2 // = 3.40282e+38
            << std::endl;

  // Pointers

  std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };

  int* vp = cmb::midpoint( v.data(), v.data() + v.size() );

  std::cout << "\n*result = " << *vp << std::endl; // = 4

}