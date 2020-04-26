// reduce.hxx

#ifndef REDUCE_HXX
#define REDUCE_HXX

#include <iterator>       // for std::iterator_traits::value_type
#include <utility>        // for std::move
#include "functional.hxx" // for cmb::plus


namespace cmb {


  // 4 parameter overload
  template <class I, // I models InputIterator
            class T, // T models Arithmetic
            class B> // B models BinaryOperation
  constexpr T
  reduce(I first, I last, T init, B binary_op)
  {
    for (; first != last; ++first)
      init = binary_op(init, *first);

    return init;
  }


  // 3 parameter overload
  template <class I, // I models InputIterator
            class T> // T models Arithmetic
  constexpr T
  reduce(I first, I last, T init)
  {
    return cmb::reduce( first, last, std::move(init), cmb::plus<>{} );
  }


  // 2 parameter overload
  template <class I> // I models InputIterator
  constexpr typename std::iterator_traits<I>::value_type
  reduce(I first, I last)
  {
    return cmb::reduce( first, last, typename std::iterator_traits<I>::value_type{} );
  }


} // namespace cmb


#endif