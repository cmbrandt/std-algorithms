// inner_product.hxx

#ifndef INNER_PRODUCT_HXX
#define INNER_PRODUCT_HXX




namespace cmb {


  // 6 parameter overload
  template <class I,  // I models InputIterator
            class T,  // T is value_type<I>
            class B1, // B2 models BinaryOperation
            class B2> // B2 models BinaryOperation
  constexpr inline T
  inner_product(I first1, I last1, I first2, T init, B1 op1, B2 op2)
  {
    for (; first1 != last1; ++first1, ++first2)
      init = op1( init, op2(*first1, *first2) );

    return init;
  }


  // 4 parameter overload
  template <class I, // I models InputIterator
            class T> // T is value_type<I>
  constexpr inline T
  inner_product(I first1, I last1, I first2, T init)
  {
    return cmb::inner_product(first1, last1, first2, init, cmb::plus<>{ },
      cmb::multiplies<>{ });
  }


} // namespace cmb


#endif