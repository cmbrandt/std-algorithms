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


#endif