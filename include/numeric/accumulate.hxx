// accumulate.hxx

#ifndef ACCUMULATE_HXX
#define ACCUMULATE_HXX

#include "functional.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models InputIterator
            class T, // T is value_type<I>
            class B> // B models BinaryOperation
  constexpr inline T
  accumulate(I first, I last, T init, B binary_op)
  {
    for (; first != last; ++first)
      init = binary_op(init, *first);

    return init;
  }


  // 3 parameter overload
  template <class I, // I models InputIterator
            class T> // T is value_type<I>
  constexpr inline T
  accumulate(I first, I last, T init)
  {
    return cmb::accumulate(first, last, init, cmb::plus<>{ });
  }


} // namespace cmb


#endif