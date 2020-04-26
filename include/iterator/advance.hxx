// advance.hxx

#ifndef ADVANCE_HXX
#define ADVANCE_HXX

#include <cassert>
#include <iterator>


namespace cmb {


  // Implementation overload for InputIterator
  template <typename I, // I models InputIterator
            typename D> // D models Integral
  constexpr void
  advance_impl(I& i, D n, std::input_iterator_tag)
  {
    assert(n >= 0);
    while (n--)
      ++i;
  }


  // Implementation overload for BidirectionalIterator
  template <typename I, // I models BidirectionalIterator
            typename D> // D models Interal
  constexpr void
  advance_impl(I& i, D n, std::bidirectional_iterator_tag)
  {
    if (n < 0)
      while (n++) --i;
    else
      while (n--) ++i;
  }


  // Implementation overload for RandomAccessIterator
  template <typename I, // I models RandomAccessIterator
            typename D> // D models Integral
  constexpr void
  advance_impl(I& i, D n, std::random_access_iterator_tag)
  {
    i += n;
  }


  // Generic function that dispatches to implementation overloads
  template <typename I, // I models InputIterator
            typename D> // D models Integral
  constexpr void
  advance(I& i, D n)
  {
    typename std::iterator_traits<I>::iterator_category iterator_tag;
    advance_impl(i, n, iterator_tag);
  }


} // namespace cmb


#endif