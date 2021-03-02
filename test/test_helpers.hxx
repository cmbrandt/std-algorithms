#ifndef TEST_HELPERS_HXX
#define TEST_HELPERS_HXX

#include <array>
#include <iostream>
#include <vector>


//
// Helper functions used within test_numeric() and test_utility()

template <class I1, class I2>
bool compare_numeric_sequences(I1 first1, I1 last1, I2 first2)
{
  using T = decltype(first1 - first2);

  int count{0};

  for (; first1 != last1; ++first1, ++first2) {
    T diff = (*first1) - (*first2);

    if ( std::abs(diff) > T{0} )
      ++count;
  }

  if (count > 0)
    return true;
  else
    return false; 
}



template <class I>
bool compare_string_sequences(I first1, I last1, I first2)
{
  int count{0};

  for (; first1 != last1; ++first1, ++first2)
    if ( (*first1) != (*first2) )
      ++count;

  if (count > 0)
    return true;
  else
    return false; 
}



template <typename I>
void print_sequence(std::string_view str, I first, I last)
{
  std::cout << str << ":" << std::endl;

  for (; first != last; ++first)
    std::cout << " " << *first;

  std::cout << std::endl;
}


#endif