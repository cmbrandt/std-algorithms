// gcd.hxx

#ifndef GCD_HXX
#define GCD_HXX

#include <type_traits> // for std::is_integral_v, std::is_same_v, std::remove_cv_t


namespace cmb {


  // Implementation function
  template <class M, // M models Integral
            class N> // N models Integral
  constexpr inline std::common_type_t<M, N>
  gcd_impl(M m, N n)
  {
    return m == 0 ? std::abs(n)
         : n == 0 ? std::abs(m)
         : gcd_impl(n, m % n);
  }


  // Generic function that invokes implementation function
  template <class M, // M models Integral
            class N> // N models Integral
  constexpr inline std::common_type_t<M, N>
  gcd(M m, N n)
  {
    // Check that M and N are integral types
    static_assert( std::is_integral_v<M>);
    static_assert( std::is_integral_v<N>);

    // Check that M and N are not type bool
    static_assert(!std::is_same_v<std::remove_cv_t<M>, bool>);
    static_assert(!std::is_same_v<std::remove_cv_t<N>, bool>);

    return gcd_impl(n, m % n);
  }


} // namespace cmb


#endif