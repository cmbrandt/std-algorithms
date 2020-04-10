// lower_bound.hxx

#ifndef LOWER_BOUND_HXX
#define LOWER_BOUND_HXX

#include "distance.hxx"
#include "less.hxx"
#include "next.hxx"


namespace nag {

  // STL-equivalent implementation (3 parameters)
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  inline I lower_bound_v1(I f, I l, T const& v)
  {
    while (f != l) {
      auto d = nag::distance(f, l);
      I m = nag::next(f, d / 2);

      if (*m < v)
        f = nag::next(m);
      else
        l = m;
    }

    return f;
  }


  //
  // STL-equivalent implementation (4 parameters)

  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  inline I lower_bound(I f, I l, T const& v, C c)
  {
    while (f != l) {
      auto d = nag::distance(f, l);
      I m = nag::next(f, d / 2);

      if ( c(*m, v) )
        f = nag::next(m);
      else
        l = m;
    }

    return f;
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  inline I lower_bound(I f, I l, T const& v)
  {
    return nag::lower_bound(f, l, v, nag::less<T>{ });
  }


} // namespace cmb


#endif