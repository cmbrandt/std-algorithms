// distance.hxx

#ifndef DISTANCE_HXX
#define DISTANCE_HXX

#include <iterator>


namespace cmb {


  // Implementation overload for InputIterator
  template <class I> // I models InputIterator
  constexpr inline typename std::iterator_traits<I>::difference_type
  distance_impl(I f, I l, std::input_iterator_tag)
  {
    typename std::iterator_traits<I>::difference_type r{0};
    for (; f != l; ++f)
      ++r;

    return r;
  }


  // Implementation overload for RandomAccessIterator
  template <class I> // I models RandomAccessIterator
  constexpr inline typename std::iterator_traits<I>::difference_type
  distance_impl(I f, I l, std::random_access_iterator_tag)
  {
    return l - f;
  }


  // Generic function that dispatches to implementation overloads
  template <class I> // I models InputIterator
  constexpr inline typename std::iterator_traits<I>::difference_type
  distance(I f, I l)
  {
    typename std::iterator_traits<I>::iterator_category iterator_tag;
    return distance_impl(f, l, iterator_tag);
  }


} // namespace nag


#endif