#include <iostream>
#include <test_algorithm.hxx>
#include <test_functional.hxx>
#include <test_iterator.hxx>
#include <test_numeric.hxx>
#include <test_utility.hxx>


int main()
{
  test_algorithm();
  test_functional();
  test_iterator();
  test_numeric();
  test_utility();

  std::cout << "\n\nend of test_main.cxx\n\n";
}