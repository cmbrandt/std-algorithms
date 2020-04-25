// adjacent_difference.hxx

#ifndef ADJACENT_DIFFERENCE_HXX
#define ADJACENT_DIFFERENCE_HXX

#include <iterator> // for std::iterator_traits::value_type
#include <utility>  // for std::move


namespace cmb{


  // 3 parameter overload
  template <class I1, // I1 models IntputIterator
            class I2> // I2 models OutputIterator
  constexpr I2
  adjacent_difference(I1 first, I1 last, I2 result)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type t1{*first};
      *result = t1;

      for (++first, ++result; first != last; ++first, ++result) {
        typename std::iterator_traits<I1>::value_type t2{*first};
        *result = t2 - t1;
        t1 = std::move(t2);
      }
    }

    return result;
  }


  // 4 parameter overload
  template <class I1, // I1 models IntputIterator
            class I2, // I2 models OutputIterator
            class B>  // B  models BinaryOperation
  constexpr I2
  adjacent_difference(I1 first, I1 last, I2 result, B binary_op)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type t1{*first};
      *result = t1;

      for (++first, ++result; first != last; ++first, ++result) {
        typename std::iterator_traits<I1>::value_type t2{*first};
        *result = binary_op(t2, t1);
        t1 = std::move(t2);
      }
    }

    return result;
  }


} // namespace cmb


#endif