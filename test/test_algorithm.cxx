// test_algorithm.cxx

#include <iostream>
#include <vector>
#include <algorithm.hxx>
#include <test_algorithm.hxx>


void test_algorithm()
{
  int fail = 0;

  fail = test_lower_bound(fail);
  fail = test_upper_bound(fail);
  fail = test_equal_range(fail);
  fail = test_binary_search(fail);

  if (fail == 0)
    std::cout << "\ntest_algorithm()  passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_algorithm()  had " << fail << " errors." << std::endl;
}



//
// Binary search tests

int test_lower_bound(int fail)
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  int v = 4;
  auto less = [ ](auto a, auto b) { return a < b; };

  auto r1 = cmb::lower_bound( x.begin(), x.end(), v );
  auto r2 = cmb::lower_bound( x.begin(), x.end(), v, less );

  if ( ( r1 - x.begin() ) != 6 or ( r2 - x.begin() ) != 6 ) {
    ++fail;
    std::cout << "\nERROR! cmb::lower_bound()"
              << "\n(r1 - x.begin() ) = " << (r1 - x.begin() )
              << "\nsoln              = " << 6
              << "\n(r2 - x.begin() ) = " << (r2 - x.begin() )
              << "\nsoln              = " << 6 << std::endl;
  }

  return fail;
}



int test_upper_bound(int fail)
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  int v = 4;
  auto less = [ ](auto a, auto b) { return a < b; };

  auto r1 = cmb::upper_bound( x.begin(), x.end(), v );
  auto r2 = cmb::upper_bound( x.begin(), x.end(), v, less );

  if ( ( r1 - x.begin() ) != 8 or ( r2 - x.begin() ) != 8 ) {
    ++fail;
    std::cout << "\nERROR! cmb::upper_bound()"
              << "\n(r1 - x.begin() ) = " << (r1 - x.begin() )
              << "\nsoln              = " << 8
              << "\n(r2 - x.begin() ) = " << (r2 - x.begin() )
              << "\nsoln              = " << 8 << std::endl;
  }

  return fail;
}



int test_equal_range(int fail)
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  int v = 4;
  auto less = [ ](auto a, auto b) { return a < b; };

  auto r1 = cmb::equal_range( x.begin(), x.end(), v );
  auto r2 = cmb::equal_range( x.begin(), x.end(), v, less );

  if ( ( r1.first  - x.begin() ) != 6 or ( r1.second  - x.begin() != 8)
    or ( r2.first  - x.begin() ) != 6 or ( r2.second  - x.begin() != 8) ) {
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

  return fail;
}



int test_binary_search(int fail)
{
  std::vector<int> x{ 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  int v = 4;
  auto less = [ ](auto a, auto b) { return a < b; };

  auto r1 = cmb::binary_search( x.begin(), x.end(), v );
  auto r2 = cmb::binary_search( x.begin(), x.end(), v, less );

  if (r1 != true or r2 != true) {
    ++fail;
    std::cout << "\nERROR! cmb::binary_search()"
              << "\nr1    = " << r1
              << "\nsoln  = " << true
              << "\nr2    = " << r2
              << "\nsoln  = " << true << std::endl;
  }

  return fail;
}