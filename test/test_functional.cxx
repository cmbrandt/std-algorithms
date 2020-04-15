// test_functional.cxx

#include <iostream>
#include "functional.hxx"


//
// Function objects used within test_functional()

template <typename T, typename C>
T arithmetic_test(T a, C arithmetic)
{
  return arithmetic(a);
}

template <typename T, typename C>
T arithmetic_test(T a, T b, C arithmetic)
{
  return arithmetic(a, b);
}

template <typename T, typename C>
bool compare_test(T a, T b, C compare)
{
  return compare(a, b);
}


//
// Begin test

void test_functional()
{
    std::cout << "\n\n\n******* test_functional() *******" << std::endl;

    int fail = 0;


    //
    // Arithmetic tests

    // Test for cmb::plus

    auto a1 = arithmetic_test(1,   2,   cmb::plus<>{ });
    auto a2 = arithmetic_test(1.2, 2.5, cmb::plus<>{ });

    if (a1 != 3 or a2 != 3.7) {
      ++fail;
      std::cout << "\nERROR! cmb::plus()"
                << "\na1    = " << a1
                << "\nsoln1 = " << 3
                << "\na2    = " << a2
                << "\nsoln1 = " << 3.7
                 << std::endl;
    }

    // Test for cmb::minus

    a1 = arithmetic_test(1,   2,   cmb::minus<>{ });
    a2 = arithmetic_test(1.2, 2.5, cmb::minus<>{ });

    if (a1 != -1 or a2 != -1.3) {
      ++fail;
      std::cout << "\nERROR! cmb::minus()"
                << "\na1    = " << a1
                << "\nsoln1 = " << -1
                << "\na2    = " << a2
                << "\nsoln1 = " << -1.3
                 << std::endl;
    }

    // Test for cmb::multiplies

    a1 = arithmetic_test(6,   2,   cmb::multiplies<>{ });
    a2 = arithmetic_test(3.5, 2.5, cmb::multiplies<>{ });

    if (a1 != 12 or a2 != 8.75) {
      ++fail;
      std::cout << "\nERROR! cmb::multiplies()"
                << "\na1    = " << a1
                << "\nsoln1 = " << 12
                << "\na2    = " << a2
                << "\nsoln1 = " << 8.75
                 << std::endl;
    }

    // Test for divides

    a1 = arithmetic_test(6,   2,   cmb::divides<>{ });
    a2 = arithmetic_test(3.5, 2.5, cmb::divides<>{ });

    if (a1 != 3 or a2 != 1.4) {
      ++fail;
      std::cout << "\nERROR! cmb::divides()"
                << "\na1    = " << a1
                << "\nsoln1 = " << 3
                << "\na2    = " << a2
                << "\nsoln1 = " << 1.4
                 << std::endl;
    }

    // Test for modulus

    a1 = arithmetic_test(7, 4, cmb::modulus<>{ });

    if (a1 != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::modulus()"
                << "\na1    = " << a1
                << "\nsoln1 = " << 3
                 << std::endl;
    }

    // Test for negate

    a1 = arithmetic_test(1,   cmb::negate<>{ });
    a2 = arithmetic_test(1.2, cmb::negate<>{ });

    if (a1 != -1 or a2 != -1.2) {
      ++fail;
      std::cout << "\nERROR! cmb::negate()"
                << "\na1    = " << a1
                << "\nsoln1 = " << -1
                << "\na2    = " << a2
                << "\nsoln1 = " << -1.2
                 << std::endl;
    }


    //
    // Comparison tests

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

    // Test for cmb::greater_equal

    b1 = compare_test(0,   5,   cmb::greater_equal<>{ });
    b2 = compare_test(0.0, 0.0, cmb::greater_equal<>{ });

    if (b1 != false or b2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::greater_equal()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << false
                << "\nb2    = " << b2
                << "\nsoln1 = " << true
                 << std::endl;
    }

    // Test for cmb::less

    b1 = compare_test(5,   0,   cmb::less<>{ });
    b2 = compare_test(0.0, 5.0, cmb::less<>{ });

    if (b1 != false or b2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::less()"
                << "\nb1    = " << b1
                << "\nsoln1 = " << false
                << "\nb2    = " << b2
                << "\nsoln1 = " << true
                 << std::endl;
    }

    // Test for cmb::less_equal

    b1 = compare_test(5,   0,   cmb::less_equal<>{ });
    b2 = compare_test(0.0, 0.0, cmb::less_equal<>{ });

    if (b1 != false or b2 != true) {
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