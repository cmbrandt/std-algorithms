// upper_bound.hxx

#ifndef UPPER_BOUND_HXX
#define UPPER_BOUND_HXX

#include "advance.hxx"
#include "distance.hxx"
#include "less.hxx"


namespace nag {

  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  inline I upper_bound(I f, I l, T const& v, C c)
  {
    auto d = nag::distance(f, l);

    while (d > 0) {
      auto h = d >> 1;
      auto m = f;
      nag::advance(m, h);

      if ( c(v, *m) )
        d = h;
      else {
        f = m;
        ++f;
        d -= h - 1;
      }
    }

  return f;
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  inline I upper_bound(I f, I l, T const& v)
  {
    return nag::upper_bound(f, l, v, nag::less<T>{ });
  }


} // namespace cmb


#endif