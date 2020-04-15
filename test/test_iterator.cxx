// test_iterator.cxx

#include <iostream>
#include <vector>
#include "iterator.hxx"


void test_iterator()
{
    std::cout << "\n\n\n******* test_iterator() *******" << std::endl;

    int fail = 0;

    // Container used throughout test
    std::vector<int> v{ 1, 2, 3 };


    //
    // Test for cmb::advance
    auto it = v.begin();
    cmb::advance(it, 2);

    if (*it != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::advance()"
                << "\n*it  = " << *it
                << "\nsoln = " << 3 << std::endl;
    }


    //
    // Test for cmb::distance

    auto dist = cmb::distance(v.begin(), v.end());

    if (dist != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::distance()"
                << "\ndist = " << dist
                << "\nsoln = " << 3 << std::endl;
    }


    //
    // Test for cmb::next

    it = v.begin();
    auto nx = cmb::next(it, 2);

    if (*nx != v[2]) {
      ++fail;
      std::cout << "\nERROR! cmb::next()"
                << "\n*nx  = " << *nx
                << "\nsoln = " << v[2] << std::endl;
    }


    //
    // Test for cmb::prev

    it = v.end();

    auto pv = cmb::prev(it, 2);

    if (*pv != v[1]) {
      ++fail;
      std::cout << "\nERROR! cmb::prev()"
                << "\n*pv  = " << *pv
                << "\nsoln = " << v[1] << std::endl;
    }


    //
    // Display test results

    if (fail == 0)
      std::cout << "\ntest_iterator() passed with zero errors." << std::endl;
    else
      std::cout << "\ntest_iterator() had " << fail << " errors." << std::endl;

}