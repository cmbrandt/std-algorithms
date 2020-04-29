// test_numeric.cxx

#include <iostream>
#include <vector>
#include "numeric.hxx"


void test_numeric()
{
  std::cout << "\n\n\n******* test_numeric() *******" << std::endl;

  // Number of tests that fail
  int fail = 0;

  // Lambdas used throught test
  auto add = [ ](auto a, auto b) { return a + b;  };
  //auto sub = [ ](auto a, auto b) { return a - b;  };
  auto mul = [ ](auto a, auto b) { return a * b;  };
  //auto neg = [ ](auto a)         { return -a;     };
  //auto x10 = [ ](auto a)         { return a * 10; };
  //auto equ = [ ](auto a, auto b) { return a == b; };

  // Data used throughout test
  std::vector<int> arv{ 1, 2, 3, 4, 5, 6, 7, 8 };
/*
  std::vector<double> ipx{ 0, 1, 2, 3, 4 };
  std::vector<double> ipy{ 5, 4, 2, 3, 1 };

  std::vector<double> trx(10007, 1.0);
  std::vector<double> trz(10007, 1.0);

  std::vector<int> psv(8, 2);
  std::vector<int> psx(8);
  std::vector<int> psy(8);

  std::vector<int> sv{ 3, 1, 4, 1, 5, 9, 2, 6 };
  std::vector<int> sx(8);
  std::vector<int> sy(8);
  std::vector<int> sz(8);

  std::vector<int> adv{ 2, 4, 6, 8, 10, 12 };
  std::vector<int> adx(6);
  std::vector<int> ady(6);
*/
  // Solutions to tests



  //
  // Numeric operations

  // cmb::accumulate

  auto r1 = cmb::accumulate( arv.begin(), arv.end(), 0 );
  auto r2 = cmb::accumulate( arv.begin(), arv.end(), 1, mul );

  if (r1 != 36 or r2 != 40320) {
    ++fail;
    std::cout << "\nERROR! cmb::accumulate()"
              << "\nr1   = " << r1
              << "\nsoln = " << 36
              << "\nr2   = " << r2
              << "\nsoln = " << 40320 << std::endl;
  }

  // cmb::reduce

  r1      = cmb::reduce( arv.begin(), arv.end() );
  r2      = cmb::reduce( arv.begin(), arv.end(), 0 );
  auto r3 = cmb::reduce( arv.begin(), arv.end(), 0, add );

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

  // cmb::inner_product
/*
  auto it = v.begin();
  cmb::advance(it, 2);

  if (*it != 3) {
    ++fail;
    std::cout << "\nERROR! cmb::inner_product()"
              << "\n*it  = " << *it
              << "\nsoln = " << 3 << std::endl;
  }
*/
  // cmb::transform_reduce
/*
  auto it = v.begin();
  cmb::advance(it, 2);

  if (*it != 3) {
    ++fail;
    std::cout << "\nERROR! cmb::transform_reduce()"
              << "\n*it  = " << *it
              << "\nsoln = " << 3 << std::endl;
  }
*/
    // cmb::partial_sum
/*
  auto it = v.begin();
  cmb::advance(it, 2);

  if (*it != 3) {
    ++fail;
    std::cout << "\nERROR! cmb::advance()"
              << "\n*it  = " << *it
              << "\nsoln = " << 3 << std::endl;
  }
*/
  // cmb::exclusive_scan
/*
  auto it = v.begin();
  cmb::advance(it, 2);

  if (*it != 3) {
    ++fail;
    std::cout << "\nERROR! cmb::exclusive_scan()"
              << "\n*it  = " << *it
              << "\nsoln = " << 3 << std::endl;
  }
*/
  // cmb::inclusive_scan
/*
  auto it = v.begin();
  cmb::advance(it, 2);

  if (*it != 3) {
    ++fail;
    std::cout << "\nERROR! cmb::inclusive_scan()"
              << "\n*it  = " << *it
              << "\nsoln = " << 3 << std::endl;
  }
*/
  // cmb::transform_exclusive_scan
/*
  auto it = v.begin();
  cmb::advance(it, 2);

  if (*it != 3) {
    ++fail;
    std::cout << "\nERROR! cmb::transform_exclusive_scan()"
              << "\n*it  = " << *it
              << "\nsoln = " << 3 << std::endl;
  }
*/





    // cmb::transform_inclusive_scan
/*
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::transform_inclusive_scan()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }
*/
    // cmb::adjacent_difference
/*
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::adjacent_difference()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }
*/
    // cmb::iota
/*
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::advance()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }
*/
    // cmb::gcd
/*
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::gcd()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }
*/
    // cmb::lcm
/*
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::lcm()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }
*/
    // cmb::midpoint
/*
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::midpoint()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }
*/


    //
    // Display test results

    if (fail == 0)
      std::cout << "\ntest_numeric() passed with zero errors." << std::endl;
    else
      std::cout << "\ntest_numeric() had " << fail << " errors." << std::endl;

}