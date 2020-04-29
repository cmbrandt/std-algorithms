// test_algorithm.cxx

#include <iostream>
#include <vector>
#include "algorithm.hxx"


void test_algorithm()
{
    std::cout << "\n******* test_algorithm() *******" << std::endl;

    int fail = 0;

    // Container used throughout test
    std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

    // Comparison function used throughout test
    auto less = [ ](auto a, auto b) { return a < b; };

    // Value used throughout test
    int v = 4;


    //
    // Binary search

    // cmb::lower_bound

    auto it1 = cmb::lower_bound(x.begin(), x.end(), v);
    auto it2 = cmb::lower_bound(x.begin(), x.end(), v, less);

    if ( (it1 - x.begin()) != 6 or (it2 - x.begin()) != 6 ) {
      ++fail;
      std::cout << "\nERROR! cmb::lower_bound()"
                << "\n(it1 - x.begin() ) = " << (it1 - x.begin() )
                << "\nsoln              = " << 6
                << "\n(it2 - x.begin() ) = " << (it2 - x.begin() )
                << "\nsoln              = " << 6 << std::endl;
    }

    // cmb::upper_bound

    it1 = cmb::upper_bound(x.begin(), x.end(), v);
    it2 = cmb::upper_bound(x.begin(), x.end(), v, less);

    if ( (it1 - x.begin()) != 8 or (it2 - x.begin()) != 8 ) {
      ++fail;
      std::cout << "\nERROR! cmb::lower_bound()"
                << "\n(it1 - x.begin() ) = " << (it1 - x.begin() )
                << "\nsoln               = " << 8
                << "\n(it2 - x.begin() ) = " << (it2 - x.begin() )
                << "\nsoln               = " << 8 << std::endl;
    }

    // cmb::equal_range

    auto r1 = cmb::equal_range(x.begin(), x.end(), v);
    auto r2 = cmb::equal_range(x.begin(), x.end(), v, less);

    if ( (r1.first  - x.begin() ) != 6 or (r1.second  - x.begin() != 8)
      or (r2.first  - x.begin() ) != 6 or (r2.second  - x.begin() != 8) ) {
      ++fail;
      std::cout << "\nERROR! cmb::equal_range()"
                << "\n(r1.first  - x.begin() ) = " << (r1.first  - x.begin() )
                << "\nsoln                     = " << 6
                << "\n(r1.second - x.begin() ) = " << (r1.second - x.begin() )
                << "\nsoln                     = " << 8
                << "\n(r2.first  - x.begin() ) = " << (r2.first  - x.begin() )
                << "\nsoln                     = " << 6
                << "\n(r2.second - x.begin() ) = " << (r2.second - x.begin() )
                << "\nsoln                     = " << 8 << std::endl;
    }

    // cmb::binary_search

    bool b = cmb::binary_search(x.begin(), x.end(), v);

    if (b != true) {
      ++fail;
      std::cout << "\nERROR! cmb::binary_search()"
                << "\nb    = " << b
                << "\nsoln = " << true << std::endl;
    }


    //
    // Display test results

    if (fail == 0)
      std::cout << "\ntest_algorithm() passed with zero errors." << std::endl;
    else
      std::cout << "\ntest_algorithm() had " << fail << " errors." << std::endl;

}