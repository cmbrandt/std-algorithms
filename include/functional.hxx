
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



  //
  // Equal To

  // Specification and implementation
  template <class T>
  struct equal_to {

    constexpr bool
    operator()(T const& x, T const& y) const
    {
      return x == y;
    }

  };

  // Total specialization
  template <>
  struct equal_to<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) == std::forward<U>(u) )
    {
      return std::forward<T>(t) == std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Not Equal To

  // Specification and implementation
  template <class T>
  struct not_equal_to {

    constexpr bool
    operator()(T const& x, T const& y) const
    {
      return x != y;
    }

  };

  // Total specialization
  template <>
  struct not_equal_to<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) != std::forward<U>(u) )
    {
      return std::forward<T>(t) != std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Greater

  // Specification and implementation
  template <class T>
  struct greater {

    constexpr bool
    operator()(T const& x, T const& y) const
    {
      return x > y;
    }

  };

  // Total specialization
  template <>
  struct greater<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) > std::forward<U>(u) )
    {
      return std::forward<T>(t) > std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Less

  // Specification and implementation
  template <class T>
  struct less {

    constexpr bool
    operator()(T const& x, T const& y) const
    {
      return x < y;
    }

  };

  // Total specialization
  template <>
  struct less<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) < std::forward<U>(u) )
    {
      return std::forward<T>(t) < std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Greater Equal

  // Specification and implementation
  template <class T>
  struct greater_equal {

    constexpr bool
    operator()(T const& x, T const& y) const
    {
      return x >= y;
    }

  };

  // Total specialization
  template <>
  struct greater_equal<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) >= std::forward<U>(u) )
    {
      return std::forward<T>(t) >= std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Less Equal

  // Specification and implementation
  template <class T>
  struct less_equal {

    constexpr bool
    operator()(T const& x, T const& y) const
    {
      return x <= y;
    }

  };

  // Total specialization
  template <>
  struct less_equal<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) <= std::forward<U>(u) )
    {
      return std::forward<T>(t) <= std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Logical And

  // Specification and implementation
  template <class T>
  struct logical_and {

    constexpr bool
    operator()(T const& x, T const& y) const
    {
      return x && y;
    }

  };

  // Total specialization
  template <>
  struct logical_and<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) && std::forward<U>(u) )
    {
      return std::forward<T>(t) && std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Logical Or

  // Specification and implementation
  template <class T>
  struct logical_or {

    constexpr bool
    operator()(T const& x, T const& y) const
    {
      return x || y;
    }

  };

  // Total specialization
  template <>
  struct logical_or<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) || std::forward<U>(u) )
    {
      return std::forward<T>(t) || std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Logical Not

  // Specification and implementation
  template <class T>
  struct logical_not {

    constexpr bool
    operator()(T const& x) const
    {
      return !x;
    }

  };

  // Total specialization
  template <>
  struct logical_not<void> {

    template <class T>
    constexpr auto
    operator()(T&& t) const -> decltype( !std::forward<T>(t) )
    {
      return !std::forward<T>(t);
    }
 
    using is_transparent = void;
  };



  //
  // Bitwise And

  // Specification and implementation
  template <class T>
  struct bit_and {

    constexpr T
    operator()(T const& x, T const& y) const
    {
      return x & y;
    }

  };

  // Total specialization
  template <>
  struct bit_and<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) & std::forward<U>(u) )
    {
      return std::forward<T>(t) & std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Bitwise Or

  // Specification and implementation
  template <class T>
  struct bit_or {

    constexpr T
    operator()(T const& x, T const& y) const
    {
      return x | y;
    }

  };

  // Total specialization
  template <>
  struct bit_or<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) | std::forward<U>(u) )
    {
      return std::forward<T>(t) | std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Bitwise Xor

  // Specification and implementation
  template <class T>
  struct bit_xor {

    constexpr T
    operator()(T const& x, T const& y) const
    {
      return x ^ y;
    }

  };

  // Total specialization
  template <>
  struct bit_xor<void> {

    template <class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const -> decltype( std::forward<T>(t) ^ std::forward<U>(u) )
    {
      return std::forward<T>(t) ^ std::forward<U>(u);
    }
 
    using is_transparent = void;
  };



  //
  // Bitwise Not

  // Specification and implementation
  template <class T>
  struct bit_not {

    constexpr T
    operator()(T const& x) const
    {
      return ~x;
    }

  };

  // Total specialization
  template <>
  struct bit_not<void> {

    template <class T>
    constexpr auto
    operator()(T&& t) const -> decltype( ~std::forward<T>(t) )
    {
      return ~std::forward<T>(t);
    }
 
    using is_transparent = void;
  };

} // namespace cmb


#endif