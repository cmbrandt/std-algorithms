// generic6.cxx

// g++-9 -std=c++17 -Wall generic6.cxx -o g6

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
#include "distance.hxx"
#include "lower_bound.hxx"


// Comparison function object
struct Compare {
  template <typename T1>
  bool operator() (T1 const& lhs, T1 const& rhs) { return lhs < rhs; }
};

bool compare(int const& lhs, int const& rhs) { return lhs < rhs; }


int main()
{
  std::array<int, 12>    a = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  std::vector<int>       v = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  std::deque<int>        d = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  std::forward_list<int> f = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };
  std::list<int>         l = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

  //
  // 3 parameter overload

  auto t1 = nag::lower_bound( a.begin(), a.end(), 4 );
  auto t2 = nag::lower_bound( v.begin(), v.end(), 4 );
  auto t3 = nag::lower_bound( d.begin(), d.end(), 4 );
  auto t4 = nag::lower_bound( f.begin(), f.end(), 4 );
  auto t5 = nag::lower_bound( l.begin(), l.end(), 4 );

  std::cout << "\n3 parameter overload:" << std::endl;
  std::cout << "t1 = " << nag::distance( a.begin(), t1 ) << std::endl;
  std::cout << "t2 = " << nag::distance( v.begin(), t2 ) << std::endl; 
  std::cout << "t3 = " << nag::distance( d.begin(), t3 ) << std::endl; 
  std::cout << "t4 = " << nag::distance( f.begin(), t4 ) << std::endl; 
  std::cout << "t5 = " << nag::distance( l.begin(), t5 ) << std::endl;

  //
  // 4 parameter overload

  t1 = nag::lower_bound( a.begin(), a.end(), 4, compare );
  t2 = nag::lower_bound( v.begin(), v.end(), 4, compare );
  t3 = nag::lower_bound( d.begin(), d.end(), 4, compare );
  t4 = nag::lower_bound( f.begin(), f.end(), 4, compare );
  t5 = nag::lower_bound( l.begin(), l.end(), 4, compare );

  std::cout << "\n4 parameter overload:" << std::endl;
  std::cout << "t1 = " << nag::distance( a.begin(), t1 ) << std::endl;
  std::cout << "t2 = " << nag::distance( v.begin(), t2 ) << std::endl; 
  std::cout << "t3 = " << nag::distance( d.begin(), t3 ) << std::endl; 
  std::cout << "t4 = " << nag::distance( f.begin(), t4 ) << std::endl; 
  std::cout << "t5 = " << nag::distance( l.begin(), t5 ) << std::endl;

}