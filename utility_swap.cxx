#include <array>
#include <iostream>
#include <utility.hxx>


int main()
{
  int x{0};
  int y{5};

  cmb::swap(x, y);

  std::cout <<   "x = " << x // = 5
            << "\ny = " << y // = 0
            << std::endl;


  std::array<int, 5> a{ 0, 1, 2, 3, 4 };
  std::array<int, 5> b{ 2, 2, 2, 2, 2 };

  cmb::swap(a, b);

  for (auto i : a)
    std::cout << " " << i; // = 2 2 2 2 2

  std::cout << std::endl;

  for (auto i : b)
    std::cout << " " << i; // = 0 1 2 3 4

  std::cout << std::endl;
}