// transform_inclusive_scan.hxx

#ifndef TRANSFORM_INCLUSIVE_SCAN_HXX
#define TRANSFORM_INCLUSIVE_SCAN_HXX

#include <iterator>       // for std::iterator_traits::value_type
#include "functional.hxx" // for cmb::plus


namespace cmb {


  // 5 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class B,  // B  models BinaryOperation
            class U,  // U  models UnaryOperation
            class T>  // T  models Arithmetic
  constexpr I2
  transform_inclusive_scan(I1 first, I1 last, I2 result, B binary_op, U unary_op, T init)
  {
    for (; first != last; ++first, ++result) {
      init = binary_op( init, unary_op(*first) );
      *result = init;
    }

    return result;
  }


  // 4 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class B,  // B  models BinaryOperation
            class U>  // U  models UnaryOperation
  constexpr I2
  transform_inclusive_scan(I1 first, I1 last, I2 result, B binary_op, U unary_op)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type init = unary_op(*first);
      *result++ = init;

      if (++first != last)
        return cmb::transform_inclusive_scan( first, last, result, binary_op,
                                              unary_op, std::move(init) );
    }

    return result;
  }


} // namespace cmb


#endif