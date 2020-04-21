// gcd.hxx

#ifndef GCD_HXX
#define GCD_HXX

#include <cmath>       // for std::abs
#include <type_traits> // for std::common_type_t


namespace cmb {


  // Implementation function
  template <class T> // T models Integral
  constexpr inline T
  gcd_impl(T m, T n)
  {
    return n == 0 ? m : gcd_impl(n, m % n);
  }

  // Generic function that invokes implementation function
  template <class M, // M models Integral
            class N> // N models Integral
  constexpr inline std::common_type_t<M, N>
  gcd(M m, N n)
  {
    using R = std::common_type_t<M, N>;

    return gcd_impl( static_cast<R>( std::abs(m) ),
                     static_cast<R>( std::abs(n) ) );
  }


} // namespace cmb


#endif