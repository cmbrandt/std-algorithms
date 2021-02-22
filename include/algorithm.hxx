#ifndef ALGORITHM_HXX
#define ALGORITHM_HXX

#include <iterator>
#include <type_traits>
#include <functional.hxx>
#include <iterator.hxx>
#include <utility.hxx>


namespace cmb {

  //
  // Declarations

  // Mutating Sequence Operations

  template <class I1, class I2>
  constexpr I2
  copy(I1 first, I1 last, I2 result);

  template <class I1, class Size, class I2>
  constexpr I2
  copy_n(I1 first, Size n, I2 result);

  template <class I1, class I2, class P>
  constexpr I2
  copy_if(I1 first, I1 last, I2 result, P pred);

  template <class I1, class I2>
  constexpr I2
  copy_backwards(I1 first, I1 last, I2 result);

  template <class I1, class I2>
  constexpr I2
  move(I1 first, I1 last, I2 result);

  template <class I1, class I2>
  constexpr I2
  move_backward(I1 first, I1 last, I2 result);

  template <class I1, class I2>
  constexpr I2
  swap_ranges(I1 first1, I1 last1, I2 first2);

  template <class I1, class I2>
  constexpr void
  iter_swap(I1 a, I2 b);

  template <class I>
  constexpr I
  rotate(I first, I middle, I last);

  template <class I1, class I2>
  constexpr I2
  rotate_copy(I1 first, I1 middle, I1 last, I2 result);



  // Binary Search

  template <class I, class T>
  constexpr I
  lower_bound(I first, I last, T const& value);
  template <class I, class T, class C>
  constexpr I
  lower_bound(I first, I last, T const& value, C compare);

  template <class I, class T>
  constexpr I
  upper_bound(I first, I last, T const& value);
  template <class I, class T, class C>
  constexpr I
  upper_bound(I first, I last, T const& value, C compare);

  template <class I, class T>
  constexpr std::pair<I, I>
  equal_range(I first, I last, T const& value);
  template <class I, class T, class C>
  constexpr std::pair<I, I>
  equal_range(I first, I last, T const& value, C compare);

  template <class I, class T>
  constexpr bool
  binary_search(I first, I last, T const& value);
  template <class I, class T, class C>
  constexpr bool
  binary_search(I first, I last, T const& value, C compare);



  namespace detail {

    //
    // Non-public set of helper functions used by copy_n to
    // convert template parameter Size to an integral type

    constexpr int
    size_to_integer(int n)                { return n; }
    constexpr unsigned
    size_to_integer(unsigned n)           { return n; }
    constexpr long
    size_to_integer(long n)               { return n; }
    constexpr unsigned long
    size_to_integer(unsigned long n)      { return n; }
    constexpr long long
    size_to_integer(long long n)          { return n; }
    constexpr unsigned long long
    size_to_integer(unsigned long long n) { return n; }
    constexpr long long
    size_to_integer(float n)              { return (long long)n; }
    constexpr long long
    size_to_integer(double n)             { return (long long)n; }
    constexpr long long
    size_to_integer(long double n)        { return (long long)n; }

  } // namespace detail



  //
  // Copy

  template <class I1, // I1 models InputIterator
            class I2> // I2 models OutputIterator
  constexpr I2
  copy(I1 first, I1 last, I2 result)
  {
    for (; first != last; ++first, (void)++result)
      *result = *first;
  
    return result;
  }


  //
  // Copy N

  template <class I1,   // I1 models InputIterator
            class Size, // Size is convertible to an integral type
            class I2>   // I2 models OutputIterator
  constexpr I2
  copy_n(I1 first, Size n, I2 result)
  {
    auto nn = cmb::detail::size_to_integer(n);

    if (nn > 0) {
      *result = *first;
      ++result;
    
      for (--nn; nn > 0; --nn) {
        ++first;
        *result = *first;
        ++result;
      }
    }
  
    return result;
  }



  //
  // Copy If

  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class P>  // P  models UnaryPredicate
  constexpr I2
  copy_if(I1 first, I1 last, I2 result, P pred)
  {
    for (; first != last; ++first)
      if ( pred(*first) ) {
        *result = *first;
        ++result;
      }

    return result;
  }



  //
  // Copy Backwards

  template <class I1, // I1 models BidirectionalIterator
            class I2> // I2 models BidirectionalIterator
  constexpr I2
  copy_backward(I1 first, I1 last, I2 result)
  {
    while (first != last)
      *--result = *--last;

    return result;
  }



  //
  // Move
  
  template <class I1, // I1 models InputIterator
            class I2> // I2 models OutputIterator
  constexpr I2
  move(I1 first, I1 last, I2 result)
  {
    for (; first != last; ++first, (void)++result)
      *result = cmb::move(*first);

    return result;
  }



  //
  // Move Backward

  template <class I1, // I1 models BidirectionalIterator
            class I2> // I2 models BidirectionalIterator
  constexpr I2
  move_backward(I1 first, I1 last, I2 result)
  {
    while (first != last)
      *--result = cmb::move(*--last);

    return result;
  }



  //
  // Swap Ranges

  template <class I1, // I1 models ForwardIterator
            class I2> // I2 models ForwardIterator
  constexpr I2
  swap_ranges(I1 first1, I1 last1, I2 first2)
  {
    for (; first1 != last1; ++first1, (void)++first2)
      cmb::iter_swap(first1, first2);
  
    return first2;
  }




  //
  // Iter Swap

  template <class I1, // I1 models ForwardIterator
            class I2> // I2 models ForwardIterator
  constexpr void
  iter_swap(I1 a, I2 b)
  {
    return cmb::swap(*a, *b);
  }



  //
  // Rotate
  
  template <class I> // I models ForwardIterator
  constexpr I
  rotate(I first, I middle, I last)
  {
    if (first == middle)
      return last;
    else if (last  == middle)
      return first;

    I i{middle};

    do {
      cmb::iter_swap(first, i);

      ++first;
      ++i;

      if (first == middle)
        middle = i;
      else if (i == last)
        i = middle;
  
    } while (i != last);

    I r{first};

    while (i != last) {
      cmb::iter_swap(first, i);

      ++first;
      ++i;

      if (first == middle)
        middle = first;
      else if (i == last)
        i = middle;
    }

    return r;
  }



  //
  // Rotate Copy

  template <class I1, // I1 models InputIterator
            class I2> // I2 models OutputIterator
  constexpr I2
  rotate_copy(I1 first, I1 middle, I1 last, I2 result)
  {
    return cmb::copy( first, middle, cmb::copy(middle, last, result) );
  }



  //
  // Lower Bound

  namespace detail {

    // Non-public implementation function
    template <class C, // C models BinaryPredicate
              class I, // I models ForwardIterator
              class T> // T is value_type<I>
    constexpr I
    lower_bound_impl(I first, I last, T const& value, C compare)
    {
      using D = typename std::iterator_traits<I>::difference_type;

      while (first != last) {

        D dist   = cmb::distance(first, last);
        I middle = cmb::next(first, dist / 2);

        if ( compare(*middle, value) )
          first  = cmb::next(middle);
        else
          last   = middle;
      }

      return first;
    }

  } // namespace detail

  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr I
  lower_bound(I first, I last, T const& value, C compare)
  {
    using C_ref = std::add_lvalue_reference_t<C>;

    return cmb::detail::lower_bound_impl<C_ref>(first, last, value, compare);
  }

  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr I
  lower_bound(I first, I last, T const& value)
  {
    return cmb::lower_bound( first, last, value, cmb::less<>{} );
  }



  //
  // Upper Bound

  namespace detail {

    // Non-public implementation function
    template <class C, // C models BinaryPredicate
              class I, // I models ForwardIterator
              class T> // T is value_type<I>
    constexpr I
    upper_bound_impl(I first, I last, T const& value, C compare)
    {
      using D = typename std::iterator_traits<I>::difference_type;
      D dist  = cmb::distance(first, last);

      while (dist > 0) {

        I middle = first;
        D half   = dist >> 1;
        cmb::advance(middle, half);

        if ( compare(value, *middle) )
          dist  = half;
        else {
          first = middle;
          ++first;
          dist -= half - 1;
        }
      }

      return first;
    }

  } // namespace detail

  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr I
  upper_bound(I first, I last, T const& value, C compare)
  {
    using C_ref = std::add_lvalue_reference_t<C>;

    return cmb::detail::upper_bound_impl<C_ref>(first, last, value, compare);
  }

  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr I
  upper_bound(I first, I last, T const& value)
  {
    return cmb::upper_bound( first, last, value, cmb::less<>{} );
  }



  //
  // Equal Range

  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr std::pair<I, I>
  equal_range(I first, I last, T const& value, C compare)
  {
    using C_ref = std::add_lvalue_reference_t<C>;

    return std::make_pair( cmb::detail::lower_bound_impl<C_ref>(first, last, value, compare),
                           cmb::detail::upper_bound_impl<C_ref>(first, last, value, compare) );
  }

  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr std::pair<I, I>
  equal_range(I first, I last, T const& value)
  {
    return cmb::equal_range( first, last, value, cmb::less<>{} );
  }



  //
  // Binary Search

  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr bool
  binary_search(I first, I last, T const& value, C compare)
  {
    using C_ref = std::add_lvalue_reference_t<C>;
    
    first = cmb::detail::lower_bound_impl<C_ref>(first, last, value, compare);
    return !(first == last) && !( compare(value, *first) );
  }

  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr bool
  binary_search(I first, I last, T const& value)
  {
    return cmb::binary_search( first, last, value, cmb::less<>{} );
  }

} // namespace cmb


#endif