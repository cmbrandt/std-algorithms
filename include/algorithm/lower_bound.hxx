// lower_bound.hxx

#ifndef LOWER_BOUND_HXX
#define LOWER_BOUND_HXX

#include "../functional.hxx"
#include "../iterator.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  inline I
  lower_bound(I f, I l, T const& v, C c)
  {
    while (f != l) {
      auto d = cmb::distance(f, l);
      I m = cmb::next(f, d / 2);

      if ( c(*m, v) )
        f = cmb::next(m);
      else
        l = m;
    }

    return f;
  }


  // 3 parameter overload
  template <class I, // I models ForwardIterator
            class T> // T is value_type<I>
  inline I
  lower_bound(I f, I l, T const& v)
  {
    return cmb::lower_bound(f, l, v, cmb::less<T>{ });
  }


} // namespace cmb


#endif