// transform_reduce.hxx

#ifndef TRANSFORM_REDUCE_HXX
#define TRANSFORM_REDUCE_HXX

#include "functional.hxx"


namespace cmb {


  // 5 parameter overload
  template <class I, // I models InputIterator
            class T, // T is value_type<I>
            class B, // B models BinaryOperation
            class U> // U models UnaryOperation
  constexpr inline T
  transform_reduce(I first, I last, T init, B binary_op, U unary_op)
  {
    for (; first != last; ++first)
      init = binary_op( init, unary_op(*first) );

    return init;
  }


  // 6 parameter overload
  template <class I,  // I models InputIterator
            class T,  // T is value_type<I>
            class B1, // B1 models BinaryOperation
            class B2> // B2 models BinaryOperation
  constexpr inline T
  transform_reduce(I first1, I last1, I first2, T init, B1 binary_op1, B2 binary_op2)
  {
    for (; first1 != last1; ++first1, ++first2)
      init = binary_op1( init, binary_op2(*first1, *first2) );

    return init;
  }


  // 4 parameter overload
  template <class I, // I models InputIterator
            class T> // T is value_type<I>
  constexpr inline T
  transform_reduce(I first1, I last1 ,I first2, T init)
  {
    return cmb::transform_reduce(first1, last1, first2, init, cmb::plus<>{ },
      cmb::multiplies<>{ });
  }


} // namespace cmb


#endif