// upper_bound.hxx

#ifndef UPPER_BOUND_HXX
#define UPPER_BOUND_HXX

//#include "../functional.hxx"
#include <functional>
#include "../iterator.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models ForwardIterator
            class T, // T is value_type<I>
            class C> // C models BinaryPredicate
  constexpr inline I
  upper_bound(I f, I l, T const& v, C c)
  {
    auto d = cmb::distance(f, l);

    while (d > 0) {
      auto h = d >> 1;
      auto m = f;
      cmb::advance(m, h);

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
  constexpr inline I
  upper_bound(I first, I last, T const& value)
  {
    return cmb::upper_bound(first, last, value, std::less<>{ });
  }


} // namespace cmb


#endif