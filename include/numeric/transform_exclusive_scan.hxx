// transform_exclusive_scan.hxx

#ifndef TRANSFORM_EXCLUSIVE_SCAN_HXX
#define TRANSFORM_EXCLUSIVE_SCAN_HXX

#include <utility> // for std::move


namespace cmb {


  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class T,  // T  models Arithmetic
            class B,  // B  models BinaryOperation
            class U>  // U  models UnaryOperation
  constexpr I2
  transform_exclusive_scan(I1 first, I1 last, I2 result, T init, B binary_op, U unary_op)
  {
    while (first != last) {
      
      auto v = init;
      init = binary_op( init, unary_op(*first) );
      ++first;
      *result++ = std::move(v);
    }

    return result;
  }


} // namespace cmb


#endif