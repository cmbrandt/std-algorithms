// lcm.hxx

#ifndef LCM_HXX
#define LCM_HXX

#include <cmath>       // for std::abs
#include <type_traits> // for std::common_type_t


namespace cmb {


  template <class M, // M models Integral
            class N> // N models Integral
  constexpr std::common_type_t<M, N>
  lcm(M m, N n)
  {
    if ( m == 0 || n == 0)
      return 0;

    using R = std::common_type_t<M, N>;

    R val1 = static_cast<R>( std::abs(m) / cmb::gcd(m, n) );
    R val2 = static_cast<R>( std::abs(n) );

    return val1 * val2;
  }


} // namespace cmb


#endif