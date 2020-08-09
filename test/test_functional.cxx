// test_functional.cxx

#include <iostream>
#include "test_functional.hxx"
#include "functional.hxx"


void test_functional()
{
  int fail = 0;

  fail = test_plus(fail);
  fail = test_minus(fail);
  fail = test_multiplies(fail);
  fail = test_divides(fail);
  fail = test_modulus(fail);
  fail = test_negate(fail);

  fail = test_equal_to(fail);
  fail = test_not_equal_to(fail);
  fail = test_greater(fail);
  fail = test_less(fail);
  fail = test_greater_equal(fail);
  fail = test_less_equal(fail);

  fail = test_logical_and(fail);
  fail = test_logical_or(fail);
  fail = test_logical_not(fail);

  fail = test_bit_and(fail);
  fail = test_bit_or(fail);
  fail = test_bit_xor(fail);
  fail = test_bit_not(fail);

  if (fail == 0)
    std::cout << "\ntest_functional() passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_functional() had " << fail << " errors." << std::endl;
}



//
// Arithmetic operation tests

int test_plus(int fail)
{
  auto r1 = binary_test( 1,   2,   cmb::plus<>{ } );
  auto r2 = binary_test( 1.2, 2.5, cmb::plus<>{ } );

  if (r1 != 3 or r2 != 3.7) {
    ++fail;
    std::cout << "\nERROR! cmb::plus()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << 3
              << "\nr2    = " << r2
              << "\nsoln2 = " << 3.7
              << std::endl;
  }

  return fail;
}



int test_minus(int fail)
{
  auto r1 = binary_test( 1,   2,   cmb::minus<>{ } );
  auto r2 = binary_test( 1.2, 2.5, cmb::minus<>{ } );

  if (r1 != -1 or r2 != -1.3) {
    ++fail;
    std::cout << "\nERROR! cmb::minus()"
                << "\nr1    = " << r1
                << "\nsoln1 = " << -1
                << "\nr2    = " << r2
                << "\nsoln2 = " << -1.3
                 << std::endl;
  }

  return fail;
}



int test_multiplies(int fail)
{
  auto r1 = binary_test( 6,   2,   cmb::multiplies<>{ } );
  auto r2 = binary_test( 3.5, 2.5, cmb::multiplies<>{ } );

  if (r1 != 12 or r2 != 8.75) {
    ++fail;
    std::cout << "\nERROR! cmb::multiplies()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << 12
              << "\nr2    = " << r2
              << "\nsoln2 = " << 8.75
              << std::endl;
  }

  return fail;
}



int test_divides(int fail)
{
  auto r1 = binary_test( 6,   2,   cmb::divides<>{ } );
  auto r2 = binary_test( 3.5, 2.5, cmb::divides<>{ } );

  if (r1 != 3 or r2 != 1.4) {
    ++fail;
    std::cout << "\nERROR! cmb::divides()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << 3
              << "\nr2    = " << r2
              << "\nsoln2 = " << 1.4
              << std::endl;
  }

  return fail;
}



int test_modulus(int fail)
{
  auto r1 = binary_test( 7, 4, cmb::modulus<>{ } );
  auto r2 = binary_test( 8, 2, cmb::modulus<>{ } );

  if (r1 != 3 or r2 != 0) {
    ++fail;
    std::cout << "\nERROR! cmb::modulus()"
                << "\nr1    = " << r1
                << "\nsoln1 = " << 3
                << "\nr2    = " << r2
                << "\nsoln2 = " << 0
                 << std::endl;
    }

  return fail;
}



int test_negate(int fail)
{
  auto r1 = unary_test( 1,   cmb::negate<>{ } );
  auto r2 = unary_test( 1.2, cmb::negate<>{ } );

  if (r1 != -1 or r2 != -1.2) {
    ++fail;
    std::cout << "\nERROR! cmb::negate()"
                << "\nr1    = " << r1
                << "\nsoln1 = " << -1
                << "\nr2    = " << r2
                << "\nsoln2 = " << -1.2
                 << std::endl;
  }

  return fail;
}



//
// Comparison tests

int test_equal_to(int fail)
{
  bool r1 = compare_test( 0,   5,   cmb::equal_to<>{ } );
  bool r2 = compare_test( 0.0, 0.0, cmb::equal_to<>{ } );

  if (r1 != false or r2 != true) {
    ++fail;
    std::cout << "\nERROR! cmb::equal_to()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << false
              << "\nr2    = " << r2
              << "\nsoln2 = " << true
              << std::endl;
  }

  return fail;
}



int test_not_equal_to(int fail)
{
  auto r1 = compare_test( 0,   5,   cmb::not_equal_to<>{ } );
  auto r2 = compare_test( 0.0, 0.0, cmb::not_equal_to<>{ } );

  if (r1 != true or r2 != false) {
    ++fail;
    std::cout << "\nERROR! cmb::not_equal_to()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << true
              << "\nr2    = " << r2
              << "\nsoln2 = " << false
              << std::endl;
  }

  return fail;
}



int test_greater(int fail)
{
  auto r1 = compare_test( 0,   5,   cmb::greater<>{ } );
  auto r2 = compare_test( 5.0, 0.0, cmb::greater<>{ } );

  if (r1 != false or r2 != true) {
    ++fail;
    std::cout << "\nERROR! cmb::greater()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << false
              << "\nr2    = " << r2
              << "\nsoln2 = " << true
              << std::endl;
  }

  return fail;
}



int test_less(int fail)
{
  auto r1 = compare_test( 0,   5,   cmb::less<>{ } );
  auto r2 = compare_test( 5.0, 0.0, cmb::less<>{ } );

  if (r1 != true or r2 != false) {
    ++fail;
    std::cout << "\nERROR! cmb::less()"
                << "\nr1    = " << r1
                << "\nsoln1 = " << true
                << "\nr2    = " << r2
                << "\nsoln2 = " << false
                 << std::endl;
    }

  return fail;
}



int test_greater_equal(int fail)
{
  auto r1 = compare_test( 0,   5,   cmb::greater_equal<>{ } );
  auto r2 = compare_test( 0.0, 0.0, cmb::greater_equal<>{ } );

  if (r1 != false or r2 != true) {
    ++fail;
    std::cout << "\nERROR! cmb::greater_equal()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << false
              << "\nr2    = " << r2
              << "\nsoln2 = " << true
              << std::endl;
  }

  return fail;
}



int test_less_equal(int fail)
{
  auto r1 = compare_test( 5,   0,   cmb::less_equal<>{ } );
  auto r2 = compare_test( 0.0, 0.0, cmb::less_equal<>{ } );

  if (r1 != false or r2 != true) {
    ++fail;
    std::cout << "\nERROR! cmb::less_equal()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << false
              << "\nr2    = " << r2
              << "\nsoln2 = " << true
              << std::endl;
  }

  return fail;
}



//
// Logical operation tests

int test_logical_and(int fail)
{
  auto r1 = binary_test( true, true,  cmb::logical_and<>{ } );
  auto r2 = binary_test( true, false, cmb::logical_and<>{ } );

  if (r1 != true or r2 != false) {
    ++fail;
    std::cout << "\nERROR! cmb::logical_and()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << true
              << "\nr2    = " << r2
              << "\nsoln2 = " << false
              << std::endl;
  }

  return fail;
}



int test_logical_or(int fail)
{
  auto r1 = binary_test( false, false, cmb::logical_or<>{ } );
  auto r2 = binary_test( true,  false, cmb::logical_or<>{ } );

  if (r1 != false or r2 != true) {
    ++fail;
    std::cout << "\nERROR! cmb::logical_or()"
                << "\nr1    = " << r1
                << "\nsoln1 = " << false
                << "\nr2    = " << r2
                << "\nsoln2 = " << true
                << std::endl;
  }

  return fail;
}



int test_logical_not(int fail)
{
  auto r1 = unary_test( true,  cmb::logical_not<>{ } );
  auto r2 = unary_test( false, cmb::logical_not<>{ } );

  if (r1 != false or r2 != true) {
    ++fail;
    std::cout << "\nERROR! cmb::logical_not()"
              << "\nr1    = " << r1
              << "\nsoln1 = " << false
              << "\nr2    = " << r2
              << "\nsoln2 = " << true
              << std::endl;
  }

  return fail;
}



//
// Bitwise operation tests

int test_bit_and(int fail)
{
  auto r = binary_test( 5, 9, cmb::bit_and<>{ } );

  if (r != 1) {
    ++fail;
    std::cout << "\nERROR! cmb::bit_and()"
              << "\nr    = " << r
              << "\nsoln = " << 1
              << std::endl;
  }

  return fail;
}



int test_bit_or(int fail)
{
  auto r = binary_test( 5, 9, cmb::bit_or<>{ } );

  if (r != 13) {
    ++fail;
    std::cout << "\nERROR! cmb::bit_or()"
              << "\nr    = " << r
              << "\nsoln = " << 13
              << std::endl;
  }

  return fail;
}



int test_bit_xor(int fail)
{
  auto r = binary_test( 5, 9, cmb::bit_xor<>{ } );

  if (r != 12) {
    ++fail;
    std::cout << "\nERROR! cmb::bit_xor()"
              << "\nr    = " << r
              << "\nsoln = " << 12
              << std::endl;
  }

  return fail;
}



int test_bit_not(int fail)
{
  auto r = unary_test( 5, cmb::bit_not<>{ } );

  if (r != -6) {
    ++fail;
    std::cout << "\nERROR! cmb::bit_not()"
              << "\nr    = " << r
              << "\nsoln = " << -6
              << std::endl;
  }

  return fail;
}