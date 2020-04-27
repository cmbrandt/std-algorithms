// equal_range.hxx

#ifndef EQUAL_RANGE_HXX
#define EQUAL_RANGE_HXX

#include "functional.hxx"
#include "lower_bound.hxx"
#include "upper_bound.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr inline std::pair<I, I>
  equal_range(I first, I last, T const& value, C compare)
  {
    return std::make_pair( cmb::lower_bound(first, last, value, compare),
                           cmb::upper_bound(first, last, value, compare) );
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr inline std::pair<I, I>
  equal_range(I first, I last, T const& value)
  {
    return cmb::equal_range( first, last, value, cmb::less<>{} );
  }


} // namespace cmb


#endif