// test_functional.cxx

#include <iostream>
#include "functional.hxx"


// Function object used within test_functional()
template <typename T, typename C>
bool compare_test(T a, T b, C compare)
{
  return compare(a, b);
}


void test_functional()
{
    std::cout << "\n\n\n  ***** test_functional() *****" << std::endl;

    int fail = 0;


    //
    // Test for cmb::equal_to

    bool b1 = compare_test(0,   5,   cmb::equal_to<>{ });
    bool b2 = compare_test(0.0, 0.0, cmb::equal_to<>{ });

    if (b1 != false or b2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::equal_to()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << false
                << "\nb2    = " << b2
                << "\nsoln1 = " << true
                 << std::endl;
    }


    //
    // Test for cmb::not_equal_to

    b1 = compare_test(0,   5,   cmb::not_equal_to<>{ });
    b2 = compare_test(0.0, 0.0, cmb::not_equal_to<>{ });

    if (b1 != true or b2 != false) {
      ++fail;
      std::cout << "\nERROR! cmb::not_equal_to()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << true
                << "\nb2    = " << b2
                << "\nsoln1 = " << false
                 << std::endl;
    }


    //
    // Test for cmb::greater

    b1 = compare_test(0,   5,   cmb::greater<>{ });
    b2 = compare_test(5.0, 0.0, cmb::greater<>{ });

    if (b1 != false or b2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::greater()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << false
                << "\nb2    = " << b2
                << "\nsoln1 = " << true
                 << std::endl;
    }


    //
    // Test for cmb::greater_equal

    b1 = compare_test(0,   5,   cmb::greater_equal<>{ });
    b2 = compare_test(0.0, 0.0, cmb::greater_equal<>{ });

    if (b1 !=false or b2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::greater_equal()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << false
                << "\nb2    = " << b2
                << "\nsoln1 = " << true
                 << std::endl;
    }


    //
    // Test for cmb::less

    b1 = compare_test(5,   0,   cmb::less<>{ });
    b2 = compare_test(0.0, 5.0, cmb::less<>{ });

    if (b1 !=false or b2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::less()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << false
                << "\nb2    = " << b2
                << "\nsoln1 = " << true
                 << std::endl;
    }


    //
    // Test for cmb::less_equal

    b1 = compare_test(5,   0,   cmb::less_equal<>{ });
    b2 = compare_test(0.0, 0.0, cmb::less_equal<>{ });

    if (b1 !=false or b2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::less_equal()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << false
                << "\nb2    = " << b2
                << "\nsoln1 = " << true
                 << std::endl;
    }


    //
    // Display test results

    if (fail == 0)
      std::cout << "\ntest_iterator() passed with zero errors." << std::endl;
    else
      std::cout << "\ntest_iterator() had " << fail << " errors." << std::endl;

}