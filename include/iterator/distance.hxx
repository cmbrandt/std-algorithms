// distance.hxx

#ifndef DISTANCE_HXX
#define DISTANCE_HXX

#include <iterator>


namespace cmb {


  // Implementation overload for InputIterator
  template <class I> // I models InputIterator
  constexpr inline typename std::iterator_traits<I>::difference_type
  distance_impl(I first, I last, std::input_iterator_tag)
  {
    typename std::iterator_traits<I>::difference_type r{0};
    for (; first != last; ++first)
      ++r;

    return r;
  }


  // Implementation overload for RandomAccessIterator
  template <class I> // I models RandomAccessIterator
  constexpr inline typename std::iterator_traits<I>::difference_type
  distance_impl(I first, I last, std::random_access_iterator_tag)
  {
    return last - first;
  }


  // Generic function that dispatches to implementation overloads
  template <class I> // I models InputIterator
  constexpr inline typename std::iterator_traits<I>::difference_type
  distance(I first, I last)
  {
    typename std::iterator_traits<I>::iterator_category iterator_tag;
    return distance_impl(first, last, iterator_tag);
  }


} // namespace nag


#endif