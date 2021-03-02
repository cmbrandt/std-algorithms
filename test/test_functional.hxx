#ifndef TEST_FUNCTIONAL_HXX
#define TEST_FUNCTIONAL_HXX


int test_plus(int);
int test_minus(int);
int test_multiplies(int);
int test_divides(int);
int test_modulus(int);
int test_negate(int);

int test_equal_to(int);
int test_not_equal_to(int);
int test_greater(int);
int test_less(int);
int test_greater_equal(int);
int test_less_equal(int);

int test_logical_and(int);
int test_logical_or(int);
int test_logical_not(int);

int test_bit_and(int);
int test_bit_or(int);
int test_bit_xor(int);
int test_bit_not(int);

void test_functional();


//
// Function objects used within test_functional.cxx

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


#endif