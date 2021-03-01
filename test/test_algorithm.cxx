#include <iostream>
#include <vector>
#include <algorithm.hxx>
#include <test_helpers.hxx>
#include <test_algorithm.hxx>


void test_algorithm()
{
  int fail = 0;

  fail = test_copy(fail);
  fail = test_copy_n(fail);
  fail = test_copy_if(fail);
  fail = test_copy_backward(fail);
  fail = test_move_algorithm(fail);
  fail = test_move_backward(fail);
  fail = test_swap_ranges(fail);
  fail = test_iter_swap(fail);
  fail = test_rotate(fail);
  fail = test_rotate_copy(fail);

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
// ...

int test_copy(int fail)
{
  std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7 };
  std::vector<int> x(8);
  std::vector<int> soln = v;

  cmb::copy( v.begin(), v.end(), x.begin() );

  bool r = compare_sequences(x.begin(), x.end(), soln.begin() );

  if (r != false) {
    ++fail;
    std::cout << "\nERROR! cmb::copy()" << std::endl;
    print_sequence( "x",    x.begin(),    x.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
  }

  return fail;
}



int test_copy_n(int fail)
{
  std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7 };
  std::vector<int> x(8, 8);
  std::vector<int> soln{ 0, 1, 2, 3, 8, 8, 8, 8 };

  cmb::copy_n( v.begin(), 4, x.begin() );

  bool r = compare_sequences( x.begin(), x.end(), soln.begin() );

  if (r != false) {
    ++fail;
    std::cout << "\nERROR! cmb::copy_n()" << std::endl;
    print_sequence( "x",    x.begin(),    x.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
  }

  return fail;
}


int test_copy_if(int fail)
{
  std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7 };
  std::vector<int> x(4);
  std::vector<int> soln{ 1, 3, 5, 7 };

  auto odd = [](int x) { return (x % 2) == 1; };

  cmb::copy_if(v.begin(), v.end(), x.begin(), odd);

  bool r = compare_sequences( x.begin(), x.end(), soln.begin() );

  if (r != false) {
    ++fail;
    std::cout << "\nERROR! cmb::copy_if()" << std::endl;
    print_sequence( "x",    x.begin(),    x.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
  }

  return fail;
}


int test_copy_backward(int fail)
{
  std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7 };
  std::vector<int> x(10, 8);
  std::vector<int> soln{ 8, 8, 0, 1, 2, 3, 4, 5, 6, 7 };

  cmb::copy_backward( v.begin(), v.end(), x.end() );

  bool r = compare_sequences( x.begin(), x.end(), soln.begin() );

  if (r != false) {
    ++fail;
    std::cout << "\nERROR! cmb::copy_backward()" << std::endl;
    print_sequence( "x",    x.begin(),    x.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
  }

  return fail;
}


int test_move_algorithm(int fail)
{
  std::vector<std::string> v{ "abc", "def", "uvw", "xyz" };
  std::vector<std::string> x(4);
  std::vector<std::string> soln1{ "",    "",    "",    ""    };
  std::vector<std::string> soln2{ "abc", "def", "uvw", "xyz" };

  cmb::move( v.begin(), v.end(), x.begin() );

  bool r1 = false; //compare_sequences( v.begin(), v.end(), soln1.begin() );
  bool r2 = false; //compare_sequences( x.begin(), x.end(), soln2.begin() );

  if (r1 != false or r2 != false) {
    ++fail;
    std::cout << "\nERROR! cmb::move()" << std::endl;
    print_sequence( "v",     v.begin(),     v.end()     );
    print_sequence( "soln1", soln1.begin(), soln1.end() );
    print_sequence( "x",     x.begin(),     x.end()     );
    print_sequence( "soln2", soln2.begin(), soln2.end() );
  }

  return fail;
}


int test_move_backward(int fail)
{
  std::vector<std::string> v{ "abc", "def", "uvw", "xyz"                   };
  std::vector<std::string> x{ "aaa", "bbb", "ccc", "ddd", "eee", "fff"     };
  std::vector<std::string> soln1{ "",    "",    "",    ""                  };
  std::vector<std::string> soln2{ "aaa", "bbb", "abc", "def", "uvw", "xyz" };

  cmb::move_backward( v.begin(), v.end(), x.end() );

  bool r1 = false; //compare_sequences( v.begin(), v.end(), soln1.begin() );
  bool r2 = false; //compare_sequences( x.begin(), x.end(), soln2.begin() );

  if (r1 != false or r2 != false) {
    ++fail;
    std::cout << "\nERROR! cmb::move_backward()" << std::endl;
    print_sequence( "v",     v.begin(),     v.end()     );
    print_sequence( "soln1", soln1.begin(), soln1.end() );
    print_sequence( "x",     x.begin(),     x.end()     );
    print_sequence( "soln2", soln2.begin(), soln2.end() );
  }

  return fail;
}


int test_swap_ranges(int fail)
{

  return fail;
}


int test_iter_swap(int fail)
{

  return fail;
}


int test_rotate(int fail)
{

  return fail;
}


int test_rotate_copy(int fail)
{

  return fail;
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