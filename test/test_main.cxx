// test_main.cxx

#include <iostream>
#include "test_algorithm.hxx"
#include "test_functional.hxx"
#include "test_iterator.hxx"
#include "test_numeric.hxx"


int main()
{
  test_algorithm();
  test_functional();
  test_iterator();
  test_numeric();

  std::cout << "\n\nend of test_main.cxx\n\n";
}