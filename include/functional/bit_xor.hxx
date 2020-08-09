// bit_xor.hxx

#ifndef BIT_XOR_HXX
#define BIT_XOR_HXX

#include <utility>


namespace cmb {


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

    template<class T, class U>
    constexpr auto
    operator()(T&& t, U&& u) const
      -> decltype( std::forward<T>(t) ^ std::forward<U>(u) )
    {
      return std::forward<T>(t) ^ std::forward<U>(u);
    }
 
    using is_transparent = void;
  };


} // namespace cmb


#endif