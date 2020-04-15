// test_algorithm.cxx

#include <iostream>
#include <vector>
#include "algorithm.hxx"


void test_algorithm()
{
    std::cout << "\n******* test_algorithm() *******" << std::endl;

    int fail = 0;

    // Container used throughout test
    std::vector<int> x = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

    // Value used throughout test
    int v = 4;


    //
    // Test for cmb::lower_bound
    auto it = cmb::lower_bound(x.begin(), x.end(), v);

    if ( (it - x.begin() ) != 6) {
      ++fail;
      std::cout << "\nERROR! cmb::lower_bound()"
                << "\n(it - x.begin() ) = " << (it - x.begin() )
                << "\nsoln              = " << 6 << std::endl;
    }


    //
    // Test for cmb::upper_bound

    it = cmb::upper_bound(x.begin(), x.end(), v);

    if ( (it - x.begin() ) != 8) {
      ++fail;
      std::cout << "\nERROR! cmb::lower_bound()"
                << "\n(it - x.begin() ) = " << (it - x.begin() )
                << "\nsoln              = " << 8 << std::endl;
    }

    //
    // Test for cmb::binary_search

    bool b = cmb::binary_search(x.begin(), x.end(), v);

    if (b != true) {
      ++fail;
      std::cout << "\nERROR! cmb::binary_search()"
                << "\nb    = " << b
                << "\nsoln = " << true << std::endl;
    }


    //
    // Test for cmb::equal_range

    auto r = cmb::equal_range(x.begin(), x.end(), v);

    if ( (r.first  - x.begin() ) != 6 or (r.second  - x.begin() != 8) ) {
      ++fail;
      std::cout << "\nERROR! cmb::equal_range()"
                << "\n(r.first  - x.begin() ) = " << (r.first  - x.begin() )
                << "\nsoln                    = " << 6
                << "\n(r.second - x.begin() ) = " << (r.second - x.begin() )
                << "\nsoln                    = " << 8 << std::endl;
    }


    //
    // Display test results

    if (fail == 0)
      std::cout << "\ntest_algorithm() passed with zero errors." << std::endl;
    else
      std::cout << "\ntest_algorithm() had " << fail << " errors." << std::endl;

}