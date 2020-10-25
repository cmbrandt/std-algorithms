// test_numeric.hxx

#ifndef TEST_NUMERIC_HXX
#define TEST_NUMERIC_HXX

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string_view>
#include <vector>


int test_accumulate(int);
int test_reduce(int);
int test_inner_product(int);
int test_transform_reduce(int);
int test_partial_sum(int);
int test_exclusive_scan(int);
int test_inclusive_scan(int);
int test_transform_exclusive_scan(int);
int test_transform_inclusive_scan(int);
int test_adjacent_difference(int);
int test_iota(int);
int test_gcd(int);
int test_lcm(int);
int test_midpoint(int);

void test_numeric();


// Helper functions used within test_numeric()

template <typename T>
bool compare_vectors(std::vector<T> a, std::vector<T> b)
{
  int count = 0;

  for (std::size_t i = 0; i < a.size(); ++i) {
    T diff = a[i] - b[i];

    if ( std::abs(diff) > T{0} )
      ++count;
  }

  if (count > 0)
    return true;
  else
    return false; 
}

template <typename T>
void print_vector(std::string_view str, std::vector<T> v)
{
  std::cout << str << ":" << std::endl;

  for (auto i : v)
    std::cout << " " << i;

  std::cout << std::endl;
}


#endif