// numeric.hxx

#ifndef NUMERIC_HXX
#define NUMERIC_HXX

#include <iterator>
#include <utility>
#include "functional.hxx"


namespace cmb {

  //
  // Declarations

  template <class I, class T>
  constexpr T
  accumulate(I first, I last, T init);
  template <class I, class T, class B>
  constexpr T
  accumulate(I first, I last, T init, B binary_op);

  template <class I>
  constexpr typename std::iterator_traits<I>::value_type
  reduce(I first, I last);
  template <class I, class T>
  constexpr T
  reduce(I first, I last, T init);
  template <class I, class T, class B>
  constexpr T
  reduce(I first, I last, T init, B binary_op);

  template <class I1, class I2, class T>
  constexpr T
  inner_product(I1 first1, I1 last1, I2 first2, T init);
  template <class I1, class I2, class T, class B1,  class B2>
  constexpr T
  inner_product(I1 first1, I1 last1, I2 first2, T init, B1 binary_op1, B2 binary_op2);

  template <class I1, class I2, class T>
  constexpr T
  transform_reduce(I1 first1, I1 last1, I2 first2, T init);
  template <class I1, class I2, class T, class B1, class B2>
  constexpr T
  transform_reduce(I1 first1, I1 last1, I2 first2, T init, B1 binary_op1, B2 binary_op2);
  template <class I, class T, class B, class U>
  constexpr T
  transform_reduce(I first, I last, T init, B binary_op, U unary_op);

  template <class I1, class I2>
  constexpr I2
  partial_sum(I1 first, I1 last, I2 result);
  template <class I1, class I2, class B>
  constexpr I2
  partial_sum(I1 first, I1 last, I2 result, B binary_op);

  template <class I1, class I2, class T>
  constexpr I2
  exclusive_scan(I1 first, I1 last, I2 result, T init);
  template <class I1, class I2, class T, class B>
  constexpr I2
  exclusive_scan(I1 first, I1 last, I2 result, T init, B binary_op);

  template <class I1, class I2>
  constexpr I2
  inclusive_scan(I1 first, I1 last, I2 result);
  template <class I1, class I2, class B>
  constexpr I2
  inclusive_scan(I1 first, I1 last, I2 result, B binary_op);
  template <class I1, class I2, class B,class T>
  constexpr I2
  inclusive_scan(I1 first, I1 last, I2 result, B binary_op, T init);

  template <class I1, class I2,class T, class B, class U>
  constexpr I2
  transform_exclusive_scan(I1 first, I1 last, I2 result, T init, B binary_op, U unary_op);

  template <class I1, class I2, class B, class U>
  constexpr I2
  transform_inclusive_scan(I1 first, I1 last, I2 result, B binary_op, U unary_op);
  template <class I1, class I2, class B, class U, class T>
  constexpr I2
  transform_inclusive_scan(I1 first, I1 last, I2 result, B binary_op, U unary_op, T init);

  template <class I1, class I2>
  constexpr I2
  adjacent_difference(I1 first, I1 last, I2 result);
  template <class I1, class I2, class B>
  constexpr I2
  adjacent_difference(I1 first, I1 last, I2 result, B binary_op);

  template <class I, class T>
  constexpr void
  iota(I first, I last, T value);

  template <class M, class N>
  constexpr std::common_type_t<M, N>
  gcd(M m, N n);

  template <class M, class N>
  constexpr std::common_type_t<M, N>
  lcm(M m, N n);

  template <class T>
  constexpr T
  midpoint(T a, T b) noexcept;
  template <class T>
  constexpr std::enable_if_t<std::is_object_v<T>, T*>
  midpoint(T* a, T* b);



  //
  // Accumulate

  // 3 parameter overload
  template <class I, // I models InputIterator
            class T> // T models Arithmetic
  constexpr T
  accumulate(I first, I last, T init)
  {
    for (; first != last; ++first)
      init = std::move(init) + *first;

    return init;
  }

  // 4 parameter overload
  template <class I, // I models InputIterator
            class T, // T models Arithmetic
            class B> // B models BinaryOperation
  constexpr T
  accumulate(I first, I last, T init, B binary_op)
  {
    for (; first != last; ++first)
      init = binary_op( std::move(init), *first );

    return init;
  }



  //
  // Reduce

  // 4 parameter overload
  template <class I, // I models InputIterator
            class T, // T models Arithmetic
            class B> // B models BinaryOperation
  constexpr T
  reduce(I first, I last, T init, B binary_op)
  {
    for (; first != last; ++first)
      init = binary_op(init, *first);

    return init;
  }

  // 3 parameter overload
  template <class I, // I models InputIterator
            class T> // T models Arithmetic
  constexpr T
  reduce(I first, I last, T init)
  {
    return cmb::reduce( first, last, std::move(init), cmb::plus<>{} );
  }

  // 2 parameter overload
  template <class I> // I models InputIterator
  constexpr typename std::iterator_traits<I>::value_type
  reduce(I first, I last)
  {
    return cmb::reduce( first, last, typename std::iterator_traits<I>::value_type{} );
  }



  //
  // Inner Product

  // 4 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models InputIterator
            class T>  // T  models Arithmetic
  constexpr T
  inner_product(I1 first1, I1 last1, I2 first2, T init)
  {
    for (; first1 != last1; ++first1, ++first2)
      init = std::move(init) + (*first1) * (*first2);

    return init;
  }

  // 6 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models InputIterator
            class T,  // T  models Arithmetic
            class B1, // B1 models BinaryOperation
            class B2> // B2 models BinaryOperation
  constexpr T
  inner_product(I1 first1, I1 last1, I2 first2, T init, B1 binary_op1, B2 binary_op2)
  {
    for (; first1 != last1; ++first1, ++first2)
      init = binary_op1( std::move(init), binary_op2(*first1, *first2) );

    return init;
  }



  //
  // Transform Reduce

  // 6 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models InputIterator
            class T,  // T  models Arithmetic
            class B1, // B1 models BinaryOperation
            class B2> // B2 models BinaryOperation
  constexpr T
  transform_reduce(I1 first1, I1 last1, I2 first2, T init, B1 binary_op1, B2 binary_op2)
  {
    for (; first1 != last1; ++first1, ++first2)
      init = binary_op1( init, binary_op2(*first1, *first2) );

    return init;
  }

  // 4 parameter overload
  template <class I1, // I1 models InputIterator
            class I2, // I2 models InputIterator
            class T>  // T  models Arithmetic
  constexpr T
  transform_reduce(I1 first1, I1 last1, I2 first2, T init)
  {
    return cmb::transform_reduce( first1, last1, first2, std::move(init),
                                  cmb::plus<>{}, cmb::multiplies<>{} );
  }

  // 5 parameter overload
  template <class I, // I models InputIterator
            class T, // T models Arithmetic
            class B, // B models BinaryOperation
            class U> // U models UnaryOperation
  constexpr T
  transform_reduce(I first, I last, T init, B binary_op, U unary_op)
  {
    for (; first != last; ++first)
      init = binary_op( init, unary_op(*first) );

    return init;
  }



  //
  // Partial Sum

  // 3 parameter overload
  template <class I1, // I1 models IntputIterator
            class I2> // I2 models OutputIterator
  constexpr I2
  partial_sum(I1 first, I1 last, I2 result)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type t{*first};
      *result = t;

      for (++first, ++result; first != last; ++first, ++result) {
        t       = std::move(t) + *first;
        *result = t;
      }
    }

    return result;
  }

  // 4 parameter overload
  template <class I1, // I1 models IntputIterator
            class I2, // I2 models OutputIterator
            class B>  // B  models BinaryOperation
  constexpr I2
  partial_sum(I1 first, I1 last, I2 result, B binary_op)
  {
    if (first != last) {

      typename std::iterator_traits<I1>::value_type t{*first};
      *result = t;

      for (++first, ++result; first != last; ++first, ++result) {
        t       = binary_op( std::move(t), *first );
        *result = t;
      }
    }

    return result;
  }



  //
  // Inclusive Scan





  //
  // Exclusive Scan





  //
  // Transform Inclusive Scan





  //
  // Transform Exclusive Scan





  //
  // Adjacent Difference





  //
  // Iota





  //
  // GCD





  // LCM





  //
  // Midpoint




}

#include "numeric/exclusive_scan.hxx"
#include "numeric/inclusive_scan.hxx"
#include "numeric/transform_exclusive_scan.hxx"
#include "numeric/transform_inclusive_scan.hxx"
#include "numeric/adjacent_difference.hxx"
#include "numeric/iota.hxx"
#include "numeric/gcd.hxx"
#include "numeric/lcm.hxx"
#include "numeric/midpoint.hxx"


#endif