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


  std::array<int, 5> v{ 0, 1, 2, 3, 4 };
  std::array<int, 5> s{ 2, 2, 2, 2, 2 };

  cmb::swap(v, s);

  for (auto i : v)
    std::cout << " " << i; // = 1, 2, 3, 4, 5

  std::cout << std::endl;

  for (auto i : s)
    std::cout << " " << i; // = 4, 5, 1, 2, 3

  std::cout << std::endl;
}