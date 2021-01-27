#ifndef ALGORITHM_HXX
#define ALGORITHM_HXX

#include <iterator>
#include <type_traits>
#include <functional.hxx>
#include <iterator.hxx>


namespace cmb {

  //
  // Declarations

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
    return cmb::lower_bound( first, last, value, cmb::less<>{ } );
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
    return cmb::upper_bound( first, last, value, cmb::less<>{ } );
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
    return cmb::equal_range( first, last, value, cmb::less<>{ } );
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
    return cmb::binary_search( first, last, value, cmb::less<>{ } );
  }

} // namespace cmb


#endif