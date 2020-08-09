// functional.hxx

#ifndef FUNCTIONAL_HXX
#define FUNCTIONAL_HXX

#include <utility>


namespace cmb {

  //
  // Declarations

  template <class T = void> struct plus;
  template <class T = void> struct minus;
  template <class T = void> struct multiplies;
  template <class T = void> struct divides;
  template <class T = void> struct modulus;
  template <class T = void> struct negate;
  template <> struct plus<void>;
  template <> struct minus<void>;
  template <> struct multiplies<void>;
  template <> struct divides<void>;
  template <> struct modulus<void>;
  template <> struct negate<void>;

  template <class T = void> struct equal_to;
  template <class T = void> struct not_equal_to;
  template <class T = void> struct greater;
  template <class T = void> struct less;
  template <class T = void> struct greater_equal;
  template <class T = void> struct less_equal;
  template <> struct equal_to<void>;
  template <> struct not_equal_to<void>;
  template <> struct greater<void>;
  template <> struct less<void>;
  template <> struct greater_equal<void>;
  template <> struct less_equal<void>;

  template <class T = void> struct logical_and;
  template <class T = void> struct logical_or;
  template <class T = void> struct logical_not;
  template <> struct logical_and<void>;
  template <> struct logical_or<void>;
  template <> struct logical_not<void>;

  template <class T = void> struct bit_and;
  template <class T = void> struct bit_or;
  template <class T = void> struct bit_xor;
  template <class T = void> struct bit_not;
  template <> struct bit_and<void>;
  template <> struct bit_or<void>;
  template <> struct bit_xor<void>;
  template <> struct bit_not<void>;


  //
  // Plus

  // Specification and implementation
  template <class T>
  struct plus {

    constexpr T
    operator()(T const& x, T const& y) const
    {
      return x + y;
    }

  };

  // Total specialization
  template <>
  struct plus<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) + std::forward<U>(u) )
    {
      return std::forward<T>(t) + std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


  //
  // Minus

  // Specification and implementation
  template <class T>
  struct minus {

    constexpr T
    operator()(T const& x, T const& y) const
    {
      return x - y;
    }

  };

  // Total specialization
  template <>
  struct minus<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) - std::forward<U>(u) )
    {
      return std::forward<T>(t) - std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


  //
  // Multiplies

  // Specification and implementation
  template <class T>
  struct multiplies {

    constexpr T
    operator()(T const& x, T const& y) const
    {
      return x * y;
    }

  };

  // Total specialization
  template <>
  struct multiplies<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) * std::forward<U>(u) )
    {
      return std::forward<T>(t) * std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


  //
  // Divides

  // Specification and implementation
  template <class T>
  struct divides {

    constexpr T
    operator()(T const& x, T const& y) const
    {
      return x / y;
    }

  };

  // Total specialization
  template <>
  struct divides<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) / std::forward<U>(u) )
    {
      return std::forward<T>(t) / std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


  //
  // Modulus

  // Specification and implementation
  template <class T>
  struct modulus {

    constexpr T
    operator()(T const& x, T const& y) const
    {
      return x % y;
    }

  };

  // Total specialization
  template <>
  struct modulus<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) % std::forward<U>(u) )
    {
      return std::forward<T>(t) % std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


  //
  // Negate

  // Specification and implementation
  template <class T>
  struct negate {

    constexpr T
    operator()(T const& x) const
    {
      return -x;
    }

  };

  // Total specialization
  template <>
  struct negate<void> {

    template <class T>
    constexpr auto
    operator()(T&& t) const -> decltype( -std::forward<T>(t) )
    {
      return -std::forward<T>(t);
    }
 
    using is_transparent = void;
  };








}



// Arithmetic operations
//#include "functional/plus.hxx"
//#include "functional/minus.hxx"
//#include "functional/multiplies.hxx"
//#include "functional/divides.hxx"
//#include "functional/modulus.hxx"
//#include "functional/negate.hxx"

// Comparisons
#include "functional/equal_to.hxx"
#include "functional/not_equal_to.hxx"
#include "functional/greater.hxx"
#include "functional/less.hxx"
#include "functional/greater_equal.hxx"
#include "functional/less_equal.hxx"

// Logical operations
#include "functional/logical_and.hxx"
#include "functional/logical_or.hxx"
#include "functional/logical_not.hxx"

// Bitwise operations
#include "functional/bit_and.hxx"
#include "functional/bit_or.hxx"
#include "functional/bit_xor.hxx"
#include "functional/bit_not.hxx"
// */


#endif