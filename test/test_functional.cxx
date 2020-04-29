// test_functional.cxx

#include <iostream>
#include "functional.hxx"


//
// Function objects used within test_functional()

template <typename T, typename Op>
T unary_test(T a, Op operation)
{
  return operation(a);
}

template <typename T, typename Op>
T binary_test(T a, T b, Op operation)
{
  return operation(a, b);
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

    // Number of tests that fail
    int fail = 0;


    //
    // Arithmetic tests

    // cmb::plus

    auto a1 = binary_test(1,   2,   cmb::plus<>{ });
    auto a2 = binary_test(1.2, 2.5, cmb::plus<>{ });

    if (a1 != 3 or a2 != 3.7) {
      ++fail;
      std::cout << "\nERROR! cmb::plus()"
                << "\na1    = " << a1
                << "\nsoln1 = " << 3
                << "\na2    = " << a2
                << "\nsoln1 = " << 3.7
                 << std::endl;
    }

    // cmb::minus

    a1 = binary_test(1,   2,   cmb::minus<>{ });
    a2 = binary_test(1.2, 2.5, cmb::minus<>{ });

    if (a1 != -1 or a2 != -1.3) {
      ++fail;
      std::cout << "\nERROR! cmb::minus()"
                << "\na1    = " << a1
                << "\nsoln1 = " << -1
                << "\na2    = " << a2
                << "\nsoln1 = " << -1.3
                 << std::endl;
    }

    // cmb::multiplies

    a1 = binary_test(6,   2,   cmb::multiplies<>{ });
    a2 = binary_test(3.5, 2.5, cmb::multiplies<>{ });

    if (a1 != 12 or a2 != 8.75) {
      ++fail;
      std::cout << "\nERROR! cmb::multiplies()"
                << "\na1    = " << a1
                << "\nsoln1 = " << 12
                << "\na2    = " << a2
                << "\nsoln1 = " << 8.75
                 << std::endl;
    }

    // cmb::divides

    a1 = binary_test(6,   2,   cmb::divides<>{ });
    a2 = binary_test(3.5, 2.5, cmb::divides<>{ });

    if (a1 != 3 or a2 != 1.4) {
      ++fail;
      std::cout << "\nERROR! cmb::divides()"
                << "\na1    = " << a1
                << "\nsoln1 = " << 3
                << "\na2    = " << a2
                << "\nsoln1 = " << 1.4
                 << std::endl;
    }

    // cmb::modulus

    a1 = binary_test(7, 4, cmb::modulus<>{ });

    if (a1 != 3) {
      ++fail;
      std::cout << "\nERROR! cmb::modulus()"
                << "\na1    = " << a1
                << "\nsoln1 = " << 3
                 << std::endl;
    }

    // cmb::negate

    a1 = unary_test(1,   cmb::negate<>{ });
    a2 = unary_test(1.2, cmb::negate<>{ });

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

    // cmb::equal_to

    bool c1 = compare_test(0,   5,   cmb::equal_to<>{ });
    bool c2 = compare_test(0.0, 0.0, cmb::equal_to<>{ });

    if (c1 != false or c2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::equal_to()"
                << "\nc1    = " << c1
                << "\nsoln1 = " << false
                << "\nc2    = " << c2
                << "\nsoln1 = " << true
                 << std::endl;
    }

    // cmb::not_equal_to

    c1 = compare_test(0,   5,   cmb::not_equal_to<>{ });
    c2 = compare_test(0.0, 0.0, cmb::not_equal_to<>{ });

    if (c1 != true or c2 != false) {
      ++fail;
      std::cout << "\nERROR! cmb::not_equal_to()"
                << "\nc1    = " << c1
                << "\nsoln1 = " << true
                << "\nc2    = " << c2
                << "\nsoln1 = " << false
                 << std::endl;
    }

    // cmb::greater

    c1 = compare_test(0,   5,   cmb::greater<>{ });
    c2 = compare_test(5.0, 0.0, cmb::greater<>{ });

    if (c1 != false or c2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::greater()"
                << "\nc1    = " << c1
                << "\nsoln1 = " << false
                << "\nc2    = " << c2
                << "\nsoln1 = " << true
                 << std::endl;
    }

    // cmb::less

    c1 = compare_test(5,   0,   cmb::less<>{ });
    c2 = compare_test(0.0, 5.0, cmb::less<>{ });

    if (c1 != false or c2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::less()"
                << "\nc1    = " << c1
                << "\nsoln1 = " << false
                << "\nc2    = " << c2
                << "\nsoln1 = " << true
                 << std::endl;
    }

    // cmb::greater_equal

    c1 = compare_test(0,   5,   cmb::greater_equal<>{ });
    c2 = compare_test(0.0, 0.0, cmb::greater_equal<>{ });

    if (c1 != false or c2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::greater_equal()"
                << "\nc1    = " << c1
                << "\nsoln1 = " << false
                << "\nc2    = " << c2
                << "\nsoln1 = " << true
                 << std::endl;
    }

    // cmb::less_equal

    c1 = compare_test(5,   0,   cmb::less_equal<>{ });
    c2 = compare_test(0.0, 0.0, cmb::less_equal<>{ });

    if (c1 != false or c2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::less_equal()"
                << "\nc1    = " << c1
                << "\nsoln1 = " << false
                << "\nc2    = " << c2
                << "\nsoln1 = " << true
                 << std::endl;
    }


    //
    // Logical operator tests

    // cmb::logical_and

    auto l1 = binary_test(true, true,  cmb::logical_and<>{ });
    auto l2 = binary_test(true, false, cmb::logical_and<>{ });

    if (l1 != true or l2 != false) {
      ++fail;
      std::cout << "\nERROR! cmb::logical_and()"
                << "\nl1    = " << l1
                << "\nsoln1 = " << true
                << "\nl2    = " << l2
                << "\nsoln1 = " << false
                 << std::endl;
    }

    // cmb::logical_or

    l1 = binary_test(false, false, cmb::logical_or<>{ });
    l2 = binary_test(true,  false, cmb::logical_or<>{ });

    if (l1 != false or l2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::logical_or()"
                << "\nl1    = " << l1
                << "\nsoln1 = " << false
                << "\nl2    = " << l2
                << "\nsoln1 = " << true
                 << std::endl;
    }

      // cmb::logical_not

    l1 = unary_test(true,  cmb::logical_not<>{ });
    l2 = unary_test(false, cmb::logical_not<>{ });

    if (l1 != false or l2 != true) {
      ++fail;
      std::cout << "\nERROR! cmb::logical_not()"
                << "\nl1    = " << l1
                << "\nsoln1 = " << false
                << "\nl2    = " << l2
                << "\nsoln1 = " << true
                 << std::endl;
    }


    //
    // Bitwise operator tests

    // cmb::bit_and

    auto b = binary_test(5, 9, cmb::bit_and<>{ });

    if (b != 1) {
      ++fail;
      std::cout << "\nERROR! cmb::bit_and()"
                << "\nb    = " << b
                << "\nsoln = " << 1
                 << std::endl;
    }

    // cmb::bit_or

    b = binary_test(5, 9, cmb::bit_or<>{ });

    if (b != 13) {
      ++fail;
      std::cout << "\nERROR! cmb::bit_or()"
                << "\nb    = " << b
                << "\nsoln = " << 13
                 << std::endl;
    }

    // cmb::bit_xor

    b = binary_test(5, 9, cmb::bit_xor<>{ });

    if (b != 12) {
      ++fail;
      std::cout << "\nERROR! cmb::bit_xor()"
                << "\nb    = " << b
                << "\nsoln = " << 12
                 << std::endl;
    }

    // cmb::bit_not

    b = unary_test(5, cmb::bit_not<>{ });

    if (b != -6) {
      ++fail;
      std::cout << "\nERROR! cmb::bit_not()"
                << "\nb    = " << b
                << "\nsoln = " << -6
                 << std::endl;
    }


    //
    // Display test results

    if (fail == 0)
      std::cout << "\ntest_iterator() passed with zero errors." << std::endl;
    else
      std::cout << "\ntest_iterator() had " << fail << " errors." << std::endl;

}