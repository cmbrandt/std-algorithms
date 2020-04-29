// test_numeric.cxx

#include <iostream>
#include <vector>
#include "numeric.hxx"


void test_numeric()
{
    std::cout << "\n\n\n******* test_numeric() *******" << std::endl;

    int fail = 0;

    // Container used throughout test
    std::vector<int> v{ 1, 2, 3 };


    //
    // Numeric operations

    // cmb::accumulate
/*
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::accumulate()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }
*/
    // cmb::reduce
/*
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::reduce()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }
*/
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