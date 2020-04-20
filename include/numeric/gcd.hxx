// gcd.hxx

#ifndef GCD_HXX
#define GCD_HXX

#include <type_traits>


namespace cmb {


  template <class M, // M models Integral
            class N> // N models Integral
  constexpr inline std::common_type_t<M, N>
  gcd_impl(M m, N n)
  {
    return m == 0 ? std::abs(n)
      : n == 0 ? std::abs(m)
      : gcd_impl(n, m % n);
  }


  template <class M, // M models Integral
            class N> // N models Integral
  constexpr inline std::common_type_t<M, N>
  gcd(M m, N n)
  {
    static_assert(std::is_integral_v<M>,
                  "gcd arguments are integers");
    static_assert(std::is_integral_v<N>,
                  "gcd arguments are integers");
    static_assert(!std::is_same_v<std::remove_cv_t<M>, bool>,
                  "gcd arguments are not bools");
    static_assert(!std::is_same_v<std::remove_cv_t<N>, bool>,
                  "gcd arguments are not bools");

    return gcd_impl(n, m % n);
  }


} // namespace cmb


#endif