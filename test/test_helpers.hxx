#ifndef TEST_HELPERS_HXX
#define TEST_HELPERS_HXX

#include <array>
#include <iostream>
#include <vector>


//
// Helper functions used within test_numeric() and test_utility()

template <typename T, std::size_t N>
bool compare_arrays(std::array<T, N> const& a, std::array<T, N> const& b)
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


template <typename T, std::size_t N>
void print_array(std::string_view str, std::array<T, N> const& v)
{
  std::cout << str << ":" << std::endl;

  for (auto i : v)
    std::cout << " " << i;

  std::cout << std::endl;
}


template <typename T>
bool compare_vectors(std::vector<T> const& a, std::vector<T> const& b)
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
void print_vector(std::string_view str, std::vector<T> const& v)
{
  std::cout << str << ":" << std::endl;

  for (auto i : v)
    std::cout << " " << i;

  std::cout << std::endl;
}


#endif