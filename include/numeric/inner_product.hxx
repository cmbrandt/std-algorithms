// inner_product.hxx

#ifndef INNER_PRODUCT_HXX
#define INNER_PRODUCT_HXX

#include <utility> // for std:move


namespace cmb {


  // 6 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models InputIterator
            class T,  // T is common_type_t<value_type<I1>, value_type<I2>>
            class B1, // B2 models BinaryOperation
            class B2> // B2 models BinaryOperation
  constexpr inline T
  inner_product(I1 first1, I1 last1, I2 first2, T init, B1 binary_op1, B2 binary_op2)
  {
    for (; first1 != last1; ++first1, ++first2)
      init = binary_op1( std::move(init), binary_op2(*first1, *first2) );

    return init;
  }


  // 4 parameter overload
  template <class I1, // I models InputIterator
            class I2, // I2 models InputIterator
            class T>  // T is common_type_t<value_type<I1>, value_type<I2>>
  constexpr inline T
  inner_product(I1 first1, I1 last1, I2 first2, T init)
  {
    for (; first1 != last1; ++first1, ++first2)
      init = std::move(init) + (*first1) * (*first2);

    return init;
  }


} // namespace cmb


#endif