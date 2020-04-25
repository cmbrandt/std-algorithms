// exclusive_scan.hxx

#ifndef EXCLUSIVE_SCAN_HXX
#define EXCLUSIVE_SCAN_HXX

#include <utility>        // for std::move
#include "functional.hxx" // for cmb::plus


namespace cmb {


  // 5 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class T,  // T  models Arithmetic
            class B>  // B  models BinaryOperation
  constexpr I2
  exclusive_scan(I1 first, I1 last, I2 result, T init, B binary_op)
  {
    while (first != last) {

      auto v = init;
      init = binary_op(init, *first);
      ++first;
      *result++ = std::move(v);
    }

    return result;
  }


  // 4 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class T>  // T  models Arithmetic
  constexpr I2
  exclusive_scan(I1 first, I1 last, I2 result, T init)
  {
    return cmb::exclusive_scan(first, last, result, init, cmb::plus<>{});
  }


} // namespace cmb


#endif