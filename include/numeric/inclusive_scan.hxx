// inclusive_scan.hxx

#ifndef INCLUSIVE_SCAN_HXX
#define INCLUSIVE_SCAN_HXX

#include <iterator>       // for std::iterator_traits::value_type
#include "functional.hxx" // for cmb::plus


namespace cmb {


  // 5 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class B,  // B  models BinaryOperation
            class T>  // T  models Arithmetic
  constexpr I2
  inclusive_scan(I1 first, I1 last, I2 result, B binary_op, T init)
  {
    for (; first != last; ++first, ++result) {
      init = binary_op(init, *first);
      *result = init;
    }

    return result;
  }


  // 4 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class B>  // B  models BinaryOperation
  constexpr I2
  inclusive_scan(I1 first, I1 last, I2 result, B binary_op)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type init = *first;
      *result++ = init;

      if (++first != last)
        return cmb::inclusive_scan(first, last, result, binary_op, std::move(init));
    }

    return result;
  }


  // 3 parameter overload
  template <class I1, // I1 models InputIterator
            class I2> // I2 models OutputIterator
  constexpr I2
  inclusive_scan(I1 first, I1 last, I2 result)
  {
    return cmb::inclusive_scan(first, last, result, cmb::plus<>{});
  }


} // namespace cmb


#endif