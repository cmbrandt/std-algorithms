// partial_sum.hxx

#ifndef PARTIAL_SUM_HXX
#define PARTIAL_SUM_HXX

#include <iterator> // for std::iterator_traits::value_type
#include <utility>  // for std::move


namespace cmb{


  // 3 parameter overload
  template <class I1, // I1 models IntputIterator
            class I2> // I2 models OutputIterator
  constexpr inline I2
  partial_sum(I1 first, I1 last, I2 result)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type t{*first};

      *result = t;
      for (++first, ++result; first != last; ++first, ++result) {
        t = std::move(t) + *first;
        *result = t;
      }
    }

    return result;
  }


  // 4 parameter overload
  template <class I1, // I1 models IntputIterator
            class I2, // I2 models OutputIterator
            class B>  // B models BinaryOperation
  constexpr inline I2
  partial_sum(I1 first, I1 last, I2 result, B binary_op)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type t{*first};
      *result = t;

      for (++first, ++result; first != last; ++first, ++result) {
        t = binary_op( std::move(t), *first );
        *result = t;
      }
    }

    return result;
  }


} // namespace cmb


#endif