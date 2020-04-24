// inclusive_scan.hxx

#ifndef INCLUSIVE_SCAN_HXX
#define INCLUSIVE_SCAN_HXX

#include "functional.hxx"


namespace cmb {


  // 5 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models OutputIterator
            class B,  // B models BinaryOperation
            class T>  // T models [ Arithmetc ?? ]
  constexpr inline I2
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
            class B>  // B models BinaryOperation
  constexpr inline I2
  inclusive_scan(I1 first, I1 last, I2 result, B binary_op)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type init = *first;
      *result++ = init;

      if (++first != last)
        return cmb::inclusive_scan(first, last, result, binary_op, init);
    }
    return result;
  }


  // 3 parameter overload
  template <class I1, // I1 models InputIterator
            class I2> // I2 models OutputIterator
  constexpr inline I2
  inclusive_scan(I1 first, I1 last, I2 result)
  {
    return cmb::inclusive_scan(first, last, result, cmb::plus<>{});
  }

} // namespace cmb


#endif