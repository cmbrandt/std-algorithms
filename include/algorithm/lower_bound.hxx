// lower_bound.hxx

#ifndef LOWER_BOUND_HXX
#define LOWER_BOUND_HXX

#include <iterator>
#include "functional.hxx"
#include "iterator.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr inline I
  lower_bound(I first, I last, T const& value, C compare)
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


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr inline I
  lower_bound(I first, I last, T const& value)
  {
    return cmb::lower_bound( first, last, value, cmb::less<>{} );
  }


} // namespace cmb


#endif