#include <iostream>
#include <vector>
#include <iterator.hxx>
#include <test_iterator.hxx>


void test_iterator()
{
  int fail = 0;

  fail = test_advance(fail);
  fail = test_distance(fail);
  fail = test_next(fail);
  fail = test_prev(fail);

  if (fail == 0)
    std::cout << "\ntest_iterator()   passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_iterator()   had " << fail << " errors." << std::endl;
}



//
// Iterator operation tests

int test_advance(int fail)
{
  std::vector<int> v{ 1, 2, 3 };
  auto r = v.begin();

  cmb::advance(r, 2);

  if (*r != 3) {
    ++fail;
    std::cout << "\nERROR! cmb::advance()"
              << "\n*r   = " << *r
              << "\nsoln = " << 3 << std::endl;
  }

  return fail;
}



int test_distance(int fail)
{
  std::vector<int> v{ 1, 2, 3 };

  auto r = cmb::distance( v.begin(), v.end() );

  if (r != 3) {
    ++fail;
    std::cout << "\nERROR! cmb::distance()"
              << "\nr    = " << r
              << "\nsoln = " << 3 << std::endl;
  }

  return fail;
}



int test_next(int fail)
{
  std::vector<int> v{ 1, 2, 3 };
  auto i = v.begin();

  auto r = cmb::next(i, 2);

  if (*r != v[2]) {
    ++fail;
    std::cout << "\nERROR! cmb::next()"
              << "\n*r   = " << *r
              << "\nsoln = " << v[2] << std::endl;
  }

  return fail;
}



int test_prev(int fail)
{
  std::vector<int> v{ 1, 2, 3 };
  auto i = v.end();

  auto r = cmb::prev(i, 2);

  if (*r != v[1]) {
    ++fail;
    std::cout << "\nERROR! cmb::prev()"
              << "\n*r   = " << *r
              << "\nsoln = " << v[1] << std::endl;
  }

  return fail;
}