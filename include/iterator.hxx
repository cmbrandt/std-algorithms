// iterator.hxx

#ifndef ITERATOR_HXX
#define ITERATOR_HXX

#include <iterator>


namespace cmb {

  //
  // Declarations

  template <typename I, typename D>
  constexpr void
  advance(I& i, D n);

  template <class I>
  constexpr typename std::iterator_traits<I>::difference_type
  distance(I first, I last);

  template <class I>
  constexpr I
  next(I x, typename std::iterator_traits<I>::difference_type n = 1);

  template <class I>
  constexpr I
  prev(I x, typename std::iterator_traits<I>::difference_type n = 1);


  //
  // Advance

  namespace detail {

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

  } // namespace detail

  // Generic function that dispatches to implementation overloads
  template <typename I, // I models InputIterator
            typename D> // D models Integral
  constexpr void
  advance(I& i, D n)
  {
    detail::advance_impl( i, n, typename std::iterator_traits<I>::iterator_category{ } );
  }


  //
  // Distance

  namespace detail {

    // Implementation overload for InputIterator
    template <class I> // I models InputIterator
    constexpr typename std::iterator_traits<I>::difference_type
    distance_impl(I first, I last, std::input_iterator_tag)
    {
      typename std::iterator_traits<I>::difference_type r{0};
      for (; first != last; ++first)
        ++r;

      return r;
    }

    // Implementation overload for RandomAccessIterator
    template <class I> // I models RandomAccessIterator
    constexpr typename std::iterator_traits<I>::difference_type
    distance_impl(I first, I last, std::random_access_iterator_tag)
    {
      return last - first;
    }

  } // namespace detail

  // Generic function that dispatches to implementation overloads
  template <class I> // I models InputIterator
  constexpr typename std::iterator_traits<I>::difference_type
  distance(I first, I last)
  {
    return detail::distance_impl( first, last, typename std::iterator_traits<I>::iterator_category{ } );
  }


  //
  // Next

  template <class I> // I models InputIterator
  constexpr I
  next(I x, typename std::iterator_traits<I>::difference_type n)
  {
    detail::advance_impl(x, n, typename std::iterator_traits<I>::iterator_category{ } );
    return x;
  }


  //
  // Prev

  template <class I> // I models BidirectionalIterator
  constexpr I
  prev(I x, typename std::iterator_traits<I>::difference_type n)
  {
    detail::advance_impl(x, -n, typename std::iterator_traits<I>::iterator_category{ } );
    return x;
  }

} // namespace cmb


#endif