// test_numeric.cxx

#include <iostream>
#include <vector>
#include "test_numeric.hxx"
#include "numeric.hxx"


void test_numeric()
{
  int fail = 0;

  fail = test_accumulate(fail);
  fail = test_reduce(fail);
  fail = test_inner_product(fail);
  fail = test_transform_reduce(fail);
  fail = test_partial_sum(fail);
  fail = test_inclusive_scan(fail);
  fail = test_exclusive_scan(fail);
  fail = test_transform_inclusive_scan(fail);
  fail = test_transform_exclusive_scan(fail);
  fail = test_adjacent_difference(fail);
  fail = test_iota(fail);
  fail = test_gcd(fail);
  fail = test_lcm(fail);
  fail = test_midpoint(fail);

  if (fail == 0)
    std::cout << "\ntest_numeric()    passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_numeric()    had " << fail << " errors." << std::endl;
}


int test_accumulate(int fail)
{
  std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
  auto mul = [ ](auto a, auto b) { return a * b; };

  auto r1 = cmb::accumulate( v.begin(), v.end(), 0 );
  auto r2 = cmb::accumulate( v.begin(), v.end(), 1, mul );

  if (r1 != 36 or r2 != 40320) {
    ++fail;
    std::cout << "\nERROR! cmb::accumulate()"
              << "\nr1   = " << r1
              << "\nsoln = " << 36
              << "\nr2   = " << r2
              << "\nsoln = " << 40320 << std::endl;
  }

  return fail;
}


int test_reduce(int fail)
{
  std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
  auto add = [ ](auto a, auto b) { return a + b; };

  auto r1 = cmb::reduce( v.begin(), v.end() );
  auto r2 = cmb::reduce( v.begin(), v.end(), 0 );
  auto r3 = cmb::reduce( v.begin(), v.end(), 0, add );

  if (r1 != 36 or r2 != 36 or r3 != 36) {
    ++fail;
    std::cout << "\nERROR! cmb::reduce()"
              << "\nr1   = " << r1
              << "\nsoln = " << 36
              << "\nr2   = " << r2
              << "\nsoln = " << 36
              << "\nr3   = " << r3
              << "\nsoln = " << 36 << std::endl;
  }

  return fail;
}


int test_inner_product(int fail)
{
  std::vector<double> x{ 0, 1, 2, 3, 4 };
  std::vector<double> y{ 5, 4, 2, 3, 1 };
  auto add = [ ](auto a, auto b) { return a + b;  };
  auto equ = [ ](auto a, auto b) { return a == b; };

  auto r1 = cmb::inner_product( x.begin(), x.end(), y.begin(), 0 );
  auto r2 = cmb::inner_product( x.begin(), x.end(), y.begin(), 0, add, equ );

  if (r1 != 21 or r2 != 2) {
    ++fail;
    std::cout << "\nERROR! cmb::inner_product()"
              << "\nr1   = " << r1
              << "\nsoln = " << 21
              << "\nr2   = " << r2
              << "\nsoln = " << 2 << std::endl;
  }

  return fail;
}


int test_transform_reduce(int fail)
{
  std::vector<double> x(10007, 1.0);
  std::vector<double> y(10007, 1.0);
  auto add = [ ](auto a, auto b) { return a + b; };
  auto sub = [ ](auto a, auto b) { return a - b; };
  auto mul = [ ](auto a, auto b) { return a * b; };
  auto neg = [ ](auto a)         { return -a; };

  auto r1 = cmb::transform_reduce( x.begin(), x.end(), y.begin(), 0 );
  auto r2 = cmb::transform_reduce( x.begin(), x.end(), y.begin(), 0, sub, mul );
  auto r3 = cmb::transform_reduce( x.begin(), x.end(), 0, add, neg );

  if (r1 != 10007 or r2 != -10007 or r3 != -10007) {
    ++fail;
    std::cout << "\nERROR! cmb::transform_reduce()"
              << "\nr1   = " << r1
              << "\nsoln = " << 10007
              << "\nr2   = " << r2
              << "\nsoln = " << -10007
              << "\nr3   = " << r3
              << "\nsoln = " << -10007 << std::endl;
  }

  return fail;
}


int test_partial_sum(int fail)
{
  std::vector<int> v(8, 2);
  std::vector<int> x(8);
  std::vector<int> y(8);
  auto mul = [ ](auto a, auto b) { return a * b; };

  cmb::partial_sum( v.begin(), v.end(), x.begin() );
  cmb::partial_sum( v.begin(), v.end(), y.begin(), mul );

  return fail;
}


int test_inclusive_scan(int fail)
{
  std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> x(8);
  std::vector<int> y(8);
  std::vector<int> z(8);
  auto mul = [ ](auto a, auto b) { return a * b; };

  cmb::inclusive_scan( v.begin(), v.end(), x.begin() );
  cmb::inclusive_scan( v.begin(), v.end(), y.begin(), mul );
  cmb::inclusive_scan( v.begin(), v.end(), z.begin(), mul, 1 );

  return fail;
}


int test_exclusive_scan(int fail)
{
  std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> x(8);
  std::vector<int> y(8);
  auto mul = [ ](auto a, auto b) { return a * b; };

  cmb::exclusive_scan( v.begin(), v.end(), x.begin(), 0 );
  cmb::exclusive_scan( v.begin(), v.end(), y.begin(), 1, mul );

  return fail;
}


int test_transform_inclusive_scan(int fail)
{
  std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> x(8);
  std::vector<int> y(8);
  auto add = [ ](auto a, auto b) { return a + b; };
  auto x10 = [ ](auto a)         { return a * 10; };

  cmb::transform_inclusive_scan( v.begin(), v.end(), x.begin(), add, x10 );
  cmb::transform_inclusive_scan( v.begin(), v.end(), y.begin(), add, x10, 0 );

  return fail;
}


int test_transform_exclusive_scan(int fail)
{
  std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> x(8);
  auto add = [ ](auto a, auto b) { return a + b; };
  auto x10 = [ ](auto a)         { return a * 10; };

  cmb::transform_exclusive_scan( v.begin(), v.end(), x.begin(), 0, add, x10 );

  return fail;
}


int test_adjacent_difference(int fail)
{
  std::vector<int> v{ 2, 4, 6, 8, 10, 12 };
  std::vector<int> x(6);
  std::vector<int> y(6);
  auto mul = [ ](auto a, auto b) { return a * b; };

  cmb::adjacent_difference( v.begin(), v.end(), x.begin() );
  cmb::adjacent_difference( v.begin(), v.end(), y.begin(), mul );

  return fail;
}


int test_iota(int fail)
{
  std::vector<double> v(8);

  cmb::iota( v.begin(), v.end(), -3.5 );

  return fail;
}


int test_gcd(int fail)
{
  int m = 8;
  int n = 12;

  auto r = cmb::gcd(m, n);

  if (r != 4) {
    ++fail;
    std::cout << "\nERROR! cmb::gcd()"
              << "\nr    = " << r
              << "\nsoln = " << 4 << std::endl;
  }

  return fail;
}


int test_lcm(int fail)
{
  int m = 8;
  int n = 12;

  auto r = cmb::lcm(m, n);

  if (r != 24) {
    ++fail;
    std::cout << "\nERROR! cmb::lcm()"
              << "\nr    = " << r
              << "\nsoln = " << 24 << std::endl;
  }

  return fail;
}


int test_midpoint(int fail)
{
  int   a = 0;
  int   b = 10;
  float x = 0;
  float y = 10;
  std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };

  auto r1 = cmb::midpoint(a, b);
  auto r2 = cmb::midpoint(x, y);
  int* r3 = cmb::midpoint( v.data(), v.data() + v.size() );

  if (r1 != 5 or r2 != 5 or *r3 != 4) {
    ++fail;
    std::cout << "\nERROR! cmb::midpoint()"
              << "\nr1   = " << r1
              << "\nsoln = " << 5
              << "\nr2   = " << r2
              << "\nsoln = " << 5
              << "\nr3   = " << *r3
              << "\nsoln = " << 4 << std::endl;
  }

  return fail;
}