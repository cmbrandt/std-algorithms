// binary_search.hxx

#ifndef BINARY_SEARCH_HXX
#define BINARY_SEARCH_HXX

//#include "../functional.hxx"
#include <functional>
#include "lower_bound.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr inline bool
  binary_search(I first, I last, T const& value, C compare)
  {
    first = cmb::lower_bound(first, last, value, compare);
    return ( !(first == last) && !(compare(value, *first)) );
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  constexpr inline bool
  binary_search(I first, I last, T const& value)
  {
    return cmb::binary_search(first, last, value, std::less<>{ });
  }


} // namespace cmb


#endif