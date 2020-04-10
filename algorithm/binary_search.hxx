// binary_search.hxx

#ifndef BINARY_SEARCH_HXX
#define BINARY_SEARCH_HXX

#include "lower_bound.hxx"


namespace nag {

  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  inline bool binary_search(I f, I l, T const& v, C c)
  {
    f = nag::lower_bound(f, l, v, c);
    return ( !(f == l) && !(v < *f) );
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  inline bool binary_search(I f, I l, T const& v)
  {
    return nag::binary_search(f, l, v, nag::less<T>{ });
  }


} // namespace cmb


#endif