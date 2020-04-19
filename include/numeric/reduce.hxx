// reduce.hxx

#ifndef REDUCE_HXX
#define REDUCE_HXX

#include <iterator>
#include "functional.hxx"


namespace cmb {


  // 4 parameter overload
  template <class I, // I models InputIterator
            class T, // T is value_type<I>
            class B> // B models BinaryOperation
  constexpr inline T
  reduce(I first, I last, T init, B binary_op)
  {
    for (; first != last; ++first)
      init = binary_op(init, *first);

    return init;
  }


  // 3 parameter overload
  template <class I, // I models InputIterator
            class T> // T is value_type<I>
  constexpr inline T
  reduce(I first, I last, T init)
  {
    return cmb::reduce(first, last, init, cmb::plus<>{ });
  }


  // 2 parameter overload
  template <class I> // I models InputIterator
  constexpr inline typename std::iterator_traits<I>::value_type
  reduce(I first, I last)
  {
    return cmb::reduce(first, last,
      typename std::iterator_traits<I>::value_type{ }, cmb::plus<>{ });
  }


} // namespace cmb


#endif