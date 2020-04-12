// test_main.cxx

// g++-9 -Wall -std=c++17 test_main.cxx test_algorithm.cxx test_functional.cxx test_iterator.cxx -I /Users/cmbrandt/projects/stl-algorithm/include -o test

//g++-9 -Wall -std=c++17 algorithm_lower_bound.cxx -I /Users/cmbrandt/projects/stl-algorithm/include -o lb

#include <iostream>
#include "test_algorithm.hxx"
#include "test_functional.hxx"
#include "test_iterator.hxx"


int main()
{
  test_algorithm();
  test_functional();
  test_iterator();

  std::cout << "\n\n\nend of test_main.cxx\n\n";
}