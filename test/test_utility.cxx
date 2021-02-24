#include <array>
#include <iostream>
#include <utility.hxx>
#include <test_helpers.hxx>
#include <test_utility.hxx>


void test_utility()
{
  int fail = 0;

  fail = test_swap(fail);
  fail = test_exchange(fail);
  fail = test_forward(fail);
  fail = test_move(fail);
  fail = test_move_if_noexcept(fail);

  if (fail == 0)
    std::cout << "\ntest_utility()    passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_utility()    had " << fail << " errors." << std::endl;
}


//
// ... tests

int test_swap(int fail)
{
  int x{0};
  int y{5};
  std::array<int, 5> a{ 0, 1, 2, 3, 4 };
  std::array<int, 5> b{ 2, 2, 2, 2, 2 };

  std::array<int, 5> soln1{ 2, 2, 2, 2, 2 };
  std::array<int, 5> soln2{ 0, 1, 2, 3, 4 };

  cmb::swap(x, y);
  cmb::swap(a, b);

  bool r3 = compare_arrays(a, soln1);
  bool r4 = compare_arrays(b, soln2);

  if (x != 5 or y != 0 or r3 != false or r4 != false) {
    ++fail;
    std::cout << "\nERROR! cmb::swap()"
              << "\nx    = " << x
              << "\nsoln = " << 5
              << "\ny    = " << y
              << "\nsoln = " << 0 << std::endl;
              print_array("a", a);
              print_array("b", a);
              print_array("soln1", soln1);
              print_array("soln2", soln2);
  }

  return fail;
}



int test_exchange(int fail)
{


  return fail;
}



int test_forward(int fail)
{


  return fail;
}



int test_move(int fail)
{


  return fail;
}



int test_move_if_noexcept(int fail)
{


  return fail;
}