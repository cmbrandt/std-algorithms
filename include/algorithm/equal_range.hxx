// equal_range.hxx

#ifndef EQUAL_RANGE_HXX
#define EQUAL_RANGE_HXX

#include <utility>
#include "lower_bound.hxx"
#include "upper_bound.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  inline std::pair<I, I>
  equal_range(I f, I l, T const& v, C c)
  {
    return std::make_pair( nag::lower_bound(f, l, v, c),
                           nag::upper_bound(f, l, v, c) );
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  inline std::pair<I, I>
  equal_range(I f, I l, T const& v)
  {
    return cmb::equal_range(f, l, v, nag::less<T>{ });
  }


} // namespace cmb


#endif