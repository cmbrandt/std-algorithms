// transform_reduce.hxx

#ifndef TRANSFORM_REDUCE_HXX
#define TRANSFORM_REDUCE_HXX

#include <utility>        // for std::move
#include "functional.hxx" // for cmb::multiplies, cmb::plus


namespace cmb {


  // 6 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models InputIterator
            class T,  // T  models Arithmetic
            class B1, // B1 models BinaryOperation
            class B2> // B2 models BinaryOperation
  constexpr T
  transform_reduce(I1 first1, I1 last1, I2 first2, T init, B1 binary_op1, B2 binary_op2)
  {
    for (; first1 != last1; ++first1, ++first2)
      init = binary_op1( init, binary_op2(*first1, *first2) );

    return init;
  }


  // 4 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models InputIterator
            class T>  // T  models Arithmetic
  constexpr T
  transform_reduce(I1 first1, I1 last1, I2 first2, T init)
  {
    return cmb::transform_reduce( first1, last1, first2, std::move(init),
                                  cmb::plus<>{}, cmb::multiplies<>{} );
  }


  // 5 parameter overload
  template <class I, // I models InputIterator
            class T, // T models Arithmetic
            class B, // B models BinaryOperation
            class U> // U models UnaryOperation
  constexpr T
  transform_reduce(I first, I last, T init, B binary_op, U unary_op)
  {
    for (; first != last; ++first)
      init = binary_op( init, unary_op(*first) );

    return init;
  }


} // namespace cmb


#endif