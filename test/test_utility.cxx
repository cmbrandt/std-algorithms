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
  int x{0};
  int y{5};

  int z = cmb::exchange(x, y);

  if (x != 5 or y != 5 or z != 0) {
    ++fail;
    std::cout << "\nERROR! cmb::exchange()"
              << "\nx    = " << x
              << "\nsoln = " << 5
              << "\ny    = " << y
              << "\nsoln = " << 5
              << "\ny    = " << z
              << "\nsoln = " << 0
              << std::endl;
  }

  return fail;
}



int test_forward(int fail)
{


  return fail;
}



int test_move(int fail)
{
  std::string s1 = "abc";
  std::string s2 = cmb::move(s1);

  std::string r1 = "";
  std::string r2 = "abc";

  if (s1 != r1 or s2 != r2) {
    ++fail;
    std::cout << "\nERROR! cmb::move()"
              << "\nr1 = " << r1
              << "\ns1 = " << s1
              << "\nr2 = " << r2
              << "\ns2 = " << s2
              << std::endl;
  }

  return fail;
}



int test_move_if_noexcept(int fail)
{


  return fail;
}