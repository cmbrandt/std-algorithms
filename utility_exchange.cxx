#include <iostream>
#include <utility.hxx>


int main()
{
  int x{0};
  int y{5};

  int z = cmb::exchange(x, 5);

  std::cout <<   "x = " << x // = 5
            << "\ny = " << y // = 5
            << "\nz = " << z // = 0
            << std::endl;
}